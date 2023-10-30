from turtle import Turtle, Screen
tim = Turtle()
screen = Screen()
screen.listen()
def forward():
    tim.forward(10)
def backward():
    tim.backward(10)
def turn_left():
    tim.left(10)
def turn_right():
    tim.right(10)
def reset():
    tim.reset()

screen.onkey(forward, "W")
screen.onkey(backward, "S")
screen.onkey(turn_left, "A")
screen.onkey(turn_right, "D")
screen.onkey(reset,"C") 
screen.exitonclick()
