# from takeoff import takeoff
from pymavlink import mavutil

the_connection=mavutil.mavlink_connection('udpin:localhost:14551')

the_connection.wait_heartbeat()
print("Heartbeat from system (system %u component %u)" %
      (the_connection.target_system, the_connection.target_component))

# command to change mode to guided
# the_connection.mav.command_long_send(the_connection.target_system, the_connection.target_component, mavutil.mavlink.MAV_CMD_NAV_GUIDED_ENABLE, 1, 0, 0, 0, 0, 0, 0, 0)

# takeoff(5)

# the_connection.mav.command_long_send(the_connection.target_system, the_connection.target_component, mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM, 0, 1, 0, 0, 0, 0, 0, 0)

# the_connection.mav.send(mavutil.mavlink.MAVLink_set_positon_target_global_int_message(10, the_connection.target_system, the_connection.target_component, mavutil.mavlink.MAV_FRAME_LOCAL_NED, int(0b110111111000), 10, 0, -10, 0, 0, 0, 0, 0, 0, 0, 0))

# the_connection.mav.command_long_send(the_connection.target_system, the_connection.target_component, mavutil.mavlink.MAV_CMD_NAV_WAYPOINT, 30, 1, 0, 350, 10, 10, 10, 10)

the_connection.mav.send(mavutil.mavlink.MAVLink_set_position_target_global_int_message(10, the_connection.target_system,
                        the_connection.target_component, mavutil.mavlink.MAV_FRAME_GLOBAL_RELATIVE_ALT, int(0b110111111000), int(-35.3629849 * 10 ** 7), int(149.1649185 * 10 ** 7), 10, 0, 0, 0, 0, 0, 0, 1.57, 0.5))


msg = the_connection.recv_match(type='COMMAND_ACK', blocking=True)
print(msg)

msg = the_connection.recv_match(type='LOCAL_POSITION_NED', blocking=True)
print(msg)