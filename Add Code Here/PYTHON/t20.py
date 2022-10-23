from turtle import *

def drawFourRays(length, radius):
      
    for i in range(4):
        penup()
        forward(radius)
        pendown()
        forward(length)
        penup()
        backward(length + radius)
        left(90)
  
penup()
goto(85, 110)
fillcolor("yellow")
pendown()
begin_fill()
circle(45)
end_fill()
penup()
goto(85, 169)
pendown()
drawFourRays(85, 54)
right(45)
drawFourRays(85, 54)
left(45)
done()