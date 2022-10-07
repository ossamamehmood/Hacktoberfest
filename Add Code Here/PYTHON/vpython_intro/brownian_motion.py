from vpython import *
import numpy as np

ball_radius = 0.2

ball = sphere(
    pos=vector(0, 0, 0),
    color=color.red,
    radius=ball_radius,
    opacity=0.6,
    make_trail=True,
    retain=200,
)

side = 4
thk = 0.2
s2 = 2 * side - thk
s3 = 2 * side + thk

wallR = box(pos=vector(side, 0, 0), size=vector(thk, s2, s3), color=color.red)
wallL = box(pos=vector(-side, 0, 0), size=vector(thk, s2, s3), color=color.red)
wallB = box(pos=vector(0, -side, 0), size=vector(s3, thk, s3), color=color.blue)
wallT = box(pos=vector(0, side, 0), size=vector(s3, thk, s3), color=color.blue)
wallBK = box(pos=vector(0, 0, -side), size=vector(s2, s2, thk), color=color.gray(0.7))

ball.mass = 10.0

g = vector(0, 0, -10)
dt = 0.3
time = 0.0
delta = 1
scene.autoscale = False

ball.p = vector(0.1, 0.1, 0.1)

wt = wtext(text="\n\n")


def setspeed(s):
    wt.text = "{:1.2f}".format(s.value)


sl = slider(min=0.1, max=3, value=1, length=220, bind=setspeed, right=15)

wt = wtext(text="{:1.2f}".format(sl.value))

scene.append_to_caption(" temperature\n")


def mass(m):
    wt.text = "{:1.2f}".format(m.value)


sl1 = slider(min=1.0, max=10, value=10, length=220, bind=mass, right=15)

wt = wtext(text="\n{:1.2f}".format(sl1.value))

scene.append_to_caption(" Mass\n")

while True:
    rate(100)

    side1 = side - thk * 0.5 - ball.radius

    ball.mass = sl1.value

    ball.radius = ball.mass / 10

    ball.pos.x = ball.pos.x + (ball.p.x / ball.mass) * dt * sl.value
    ball.pos.y = ball.pos.y + (ball.p.y / ball.mass) * dt * sl.value
    ball.pos.z = ball.pos.z + (ball.p.z / ball.mass) * dt * sl.value

    if not (side1 > ball.pos.x > -side1):
        ball.p.x = -ball.p.x
    if not (side1 > ball.pos.y > -side1):
        ball.p.y = -ball.p.y
    if not (side1 > ball.pos.z > -side1):
        ball.p.z = -ball.p.z

    if side1 > ball.pos.x > -side1:
        ball.p.x = delta ** 2 * np.random.normal()
    elif side1 > ball.pos.y > -side1:
        ball.p.y = delta ** 2 * np.random.normal()
    elif side1 > ball.pos.z > -side1:
        ball.p.z = delta ** 2 * np.random.normal()
