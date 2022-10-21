TOTAL_PADDLE =2
import turtle as t

class Paddle(t.Turtle):
    def __init__(self, postion):
        super().__init__()
        self.new_pad = []
        self.penup()
        self.shape("square")
        self.shapesize(stretch_len=5, stretch_wid=1)
        self.color("white")
        self.setheading(90)
        self.setpos(postion)






    def goUp(self):

        new_y = self.ycor() + 20
        self.goto(self.xcor(), new_y)

    def goDown(self):

        new_y = self.ycor() - 20
        self.goto(self.xcor(), new_y)