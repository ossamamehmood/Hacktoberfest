'''
Simple gait generator, based on an ellipsoid path.
Derived from chapter 2 in paper:
G. Endo, J. Morimoto, T. Matsubara, J. Nakanishi, and G. Cheng,
“Learning CPG-based Biped Locomotion with a Policy Gradient Method: Application to a Humanoid Robot,”
The International Journal of Robotics Research, vol. 27, no. 2, pp. 213-228,
Feb. 2008, doi: 10.1177/0278364907084980.
'''

import numpy as np
from .pose_estimator import PoseEstimator


class EllipsoidGaitGenerator():
    MAX_STEP_LENGTH_FRONT = 0.045
    MAX_STEP_LENGTH_SIDE = 0.016
    MIN_Z = -0.327

    def __init__(self, robot, time_step):
        self.robot = robot
        self.time_step = time_step
        self.theta = 0  # angle of the ellipsoid path
        self.pose_estimator = PoseEstimator(robot, time_step)
        self.right_foot_sensor = robot.getDevice('RFsr')
        self.right_foot_sensor.enable(self.time_step)
        self.left_foot_sensor = robot.getDevice('LFsr')
        self.left_foot_sensor.enable(self.time_step)

        self.roll_reflex_factor = 4e-2  # h_VSR in the paper
        # the force reflex factor is h_ER/(mass*gravity) in the paper
        self.force_reflex_factor = 1e-2 / (5.305 * 9.81)
        self.robot_height_offset = 0.31  # desired height for the robot's center of mass
        self.lateral_leg_offset = 0.05  # y distance between the center of mass and one foot
        self.step_period = 0.4  # time to complete one step
        # amplitudes of stride:
        self.step_length_front = self.MAX_STEP_LENGTH_FRONT  # when heading in the front direction (x axis)
        self.step_length_side = self.MAX_STEP_LENGTH_SIDE  # when heading in the side direction (y axis)
        self.in_place_step_length = 0.02  # when turning in place
        self.step_height = 0.04  # height of the ellipsoid path
        self.step_penetration = 0.005  # depth of the ellipsoid path
        # turning radii are bigger than desired in simulation so we multiply by this factor:
        self.radius_calibration = 0.93

    def update_theta(self):
        '''Update the angle of the ellipsoid path and clip it to [-pi, pi]'''
        self.theta = -(2 * np.pi * self.robot.getTime() / self.step_period) % (2 * np.pi) - np.pi

    def compute_leg_position(self, is_left, desired_radius=1e3, heading_angle=0):
        '''Compute the desired positions of a leg for a desired radius (R > 0 is a right turn).'''
        factor = -1 if is_left else 1  # the math is the same for both legs, except for some signs
        desired_radius *= self.radius_calibration
        if abs(desired_radius) > 0.1:
            amplitude_x = self.adapt_step_length(heading_angle) \
                * (desired_radius - factor * self.lateral_leg_offset) / desired_radius
            x = factor * amplitude_x * np.cos(self.theta)
            yaw = - x / (desired_radius - factor * self.lateral_leg_offset)
            y = - (1 - np.cos(yaw)) * (desired_radius - factor * self.lateral_leg_offset)
            if heading_angle != 0:
                x, y = self.rotate(x, y, heading_angle)
        else:
            # if the desired radius is too small for the previous calculations, rotate in place
            rotate_right = -1 if desired_radius > 0 else 1
            turning_radius = -2 * self.lateral_leg_offset
            amplitude_x = self.in_place_step_length \
                * (turning_radius * rotate_right - factor * self.lateral_leg_offset) / turning_radius * rotate_right
            x = factor * amplitude_x * np.cos(self.theta)
            yaw = - x / (turning_radius * rotate_right - factor * self.lateral_leg_offset)
            y = - (1 - np.cos(yaw)) * (turning_radius * rotate_right - factor * self.lateral_leg_offset)
        y += - factor * self.lateral_leg_offset
        z = self.compute_z(is_left)
        # TODO: clip position to possible range?
        # print('is_left', is_left, 'x: ', x, 'y: ', y, 'yaw: ', yaw)
        return x, y, z, yaw

    def compute_z(self, is_left):
        '''Takes care of the feet alternance and takes into account the vestibulospinal reflex and the extensor response.'''
        factor = -1 if is_left else 1
        amplitude_z = self.step_penetration if factor * self.theta < 0 else self.step_height
        # vestibulospinal reflex: corrects the robot's roll
        amplitude_z += factor * self.pose_estimator.get_roll_pitch_yaw()[0] * self.roll_reflex_factor
        # extensor response: pushes on the leg when it is on the ground
        force_values = self.left_foot_sensor.getValues() if is_left else self.right_foot_sensor.getValues()
        force_magnitude = np.linalg.norm(np.array([force_values[0], force_values[1], force_values[2]]))
        if force_magnitude > 5:
            amplitude_z += self.force_reflex_factor * force_magnitude
        z = factor * amplitude_z * np.sin(self.theta) - self.robot_height_offset
        # we clip the z value to avoid infeasible positions
        return z if z > self.MIN_Z else self.MIN_Z

    def adapt_step_length(self, heading_angle):
        '''Adapt the step length to the heading angle (side steps are smaller than straight steps).'''
        # need to bring the heading angle from [-pi, pi] to [0, pi/2]
        if heading_angle < 0:
            heading_angle = - heading_angle
        if heading_angle > np.pi / 2:
            heading_angle = np.pi - heading_angle
        factor = heading_angle / (np.pi / 2)
        amplitude = self.step_length_front * (1 - factor) + self.step_length_side * factor
        return amplitude

    def set_step_amplitude(self, amount):
        '''Set the amplitude of the step. amount is between 0 and 1.'''
        self.step_length_front = self.MAX_STEP_LENGTH_FRONT * amount
        self.step_length_side = self.MAX_STEP_LENGTH_SIDE * amount

    @staticmethod
    def rotate(x, y, angle):
        '''Rotate a point by a given angle.'''
        return x * np.cos(angle) - y * np.sin(angle), x * np.sin(angle) + y * np.cos(angle)
