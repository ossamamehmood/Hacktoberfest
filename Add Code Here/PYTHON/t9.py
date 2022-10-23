import turtle
import math
 
# Set the background color
screen = turtle.Screen()
screen.bgcolor("lightpink")
 
# Create our turtle
t = turtle.Turtle()
t.color("black")
t.shape("turtle")
t.speed(1)
 
# Define a function to draw and
# fill a rectangle with the given
# dimensions and color
def drawRectangle(t, width, height, color):
   
    t.fillcolor(color)
    t.begin_fill()
    t.forward(width)
    t.left(90)
    t.forward(height)
    t.left(90)
    t.forward(width)
    t.left(90)
    t.forward(height)
    t.left(90)
    t.end_fill()
 
 
# Define a function to draw and fill an equalateral right
# triangle with the given hypotenuse length and color.  This
# is used to create a roof shape.
def drawTriangle(t, length, color):
    t.fillcolor(color)
    t.begin_fill()
    t.forward(length)
    t.left(135)
    t.forward(length / math.sqrt(2))
    t.left(90)
    t.forward(length / math.sqrt(2))
    t.left(135)
    t.end_fill()
 
 
# Define a function to draw and fill a parallelogram, used to
# draw the side of the house
def drawParallelogram(t, width, height, color):
    t.fillcolor(color)
    t.begin_fill()
    t.left(30)
    t.forward(width)
    t.left(60)
    t.forward(height)
    t.left(120)
    t.forward(width)
    t.left(60)
    t.forward(height)
    t.left(90)
    t.end_fill()
 
 
# Draw and fill the front of the house
t.penup()
t.goto(-150, -120)
t.pendown()
drawRectangle(t, 100, 110, "blue")
 
# Draw and fill the front door
t.penup()
t.goto(-120, -120)
t.pendown()
drawRectangle(t, 40, 60, "lightgreen")
 
# Front roof
t.penup()
t.goto(-150, -10)
t.pendown()
drawTriangle(t, 100, "magenta")
 
# Side of the house
t.penup()
t.goto(-50, -120)
t.pendown()
drawParallelogram(t, 60, 110, "yellow")
 
# Window
t.penup()
t.goto(-30, -60)
t.pendown()
drawParallelogram(t, 20, 30, "brown")
 
# Side roof
t.penup()
t.goto(-50, -10)
t.pendown()
t.fillcolor("orange")
t.begin_fill()
t.left(30)
t.forward(60)
t.left(105)
t.forward(100 / math.sqrt(2))
t.left(75)
t.forward(60)
t.left(105)
t.forward(100 / math.sqrt(2))
t.left(45)
t.end_fill()
turtle.done()