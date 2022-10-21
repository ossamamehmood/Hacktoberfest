import turtle 
pen = turtle.Turtle()
def draw(space,x):
  for i in range(x):
    for j in range(x):
        pen.dot()
        pen.forward(space)
    pen.backward(space*x)  
    pen.right(90)
    pen.forward(space)
    pen.left(90)
  

pen.penup()
draw(10,8)
pen.hideturtle()
turtle.done()