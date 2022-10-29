#!/bin/python3

from turtle import *
from random import randint

speed(0)
penup()
goto(-140, 140)

for step in range(15):
  write(step, align='center')
  right(90)
  for num in range(8):
    penup()
    forward(10)
    pendown()
    forward(10)
  penup()
  backward(160)
  left(90)
  forward(20)

ada = Turtle()
ada.color('red')
ada.shape('turtle')

ada.penup()
ada.goto(-160, 100)
ada.pendown()

for turn in range(10):
  ada.right(36)

bob = Turtle()
bob.color('blue')
bob.shape('turtle')

bob.penup()
bob.goto(-160, 70)
bob.pendown()

for turn in range(72):
  bob.left(5)

ivy = Turtle()
ivy.shape('turtle')
ivy.color('green')

ivy.penup()
ivy.goto(-160, 40)
ivy.pendown()

for turn in range(60):
  ivy.right(6)

jim = Turtle()
jim.shape('turtle')
jim.color('orange')

jim.penup()
jim.goto(-160, 10)
jim.pendown()

for turn in range(30):
  jim.left(12)

for turn in range(100):
  ada.forward(randint(1,5))
  bob.forward(randint(1,5))
  ivy.forward(randint(1,5))
  jim.forward(randint(1,5))
  