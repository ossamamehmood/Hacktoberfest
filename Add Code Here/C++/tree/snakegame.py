import turtle
import time
import random

delay = 0.1
segments = []
score = 0
high_score = 0

wn = turtle.Screen()
wn.title("Snake Game")
wn.bgcolor("black")
wn.setup(width=600, height=600)
wn.tracer(0)

head = turtle.Turtle()
head.shape("circle")
head.color("green")
head.speed(0)
head.penup()
head.goto(0,0)
head.direction = "stop"

food = turtle.Turtle()
food.speed(0)
food.shape("triangle")
food.color("red")
food.penup()
food.shapesize(0.5,0.5)
food.goto(0,150)

pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0,260)
pen.write("Score : 0 High score : 0",align="center", font=("courier",18,"normal"))


def go_up():
    if head.direction != "down":
        head.direction="up"

def go_down():
    if head.direction != "up":
        head.direction="down"

def go_right():
    if head.direction != "left":
        head.direction="right"

def go_left():
    if head.direction != "right":
        head.direction = "left"

def move():
    if head.direction =="up":
        y=head.ycor()
        head.sety(y+20)

    if head.direction =="down":
        y=head.ycor()
        head.sety(y-20)

    if head.direction =="left":
        x=head.xcor()
        head.setx(x-20)

    if head.direction =="right":
        x=head.xcor()
        head.setx(x+20)

wn.listen()
wn.onkeypress(go_up,"w")
wn.onkeypress(go_down,"s")
wn.onkeypress(go_right,"d")
wn.onkeypress(go_left,"a")
while True:
    wn.update()

    if head.xcor()>290 or head.xcor()<-290 or head.ycor()>290 or head.ycor()<-290:
        time.sleep(2)
        head.goto(0,0)
        head.direction = "stop"
        for seg in segments:
            seg.goto(1000,1000)
        segments.clear()

        score = 0
        pen.clear()
        pen.write("Score : {} High Score : {}".format(score, high_score), align="center",
                  font=("Courier", 18, "normal"))

    if head.distance(food)<15:
        x = random.randint(-290,290)
        y = random.randint(-290,290)
        food.goto(x,y)
        new_segment = turtle.Turtle()
        new_segment.speed(0)
        new_segment.shape("circle")
        new_segment.color("green")
        new_segment.penup()
        segments.append(new_segment)

        score += 10
        if score > high_score:
            high_score = score
            pen.clear()
            pen.write("Score : {} High Score : {}".format(score, high_score), align="center", font=("Courier", 18, "normal"))


    for index in range(len(segments)-1,0,-1):
        x = segments[index-1].xcor()
        y = segments[index-1].ycor()
        segments[index].goto(x,y)
    if len(segments)>0:
        x = head.xcor()
        y = head.ycor()
        segments[0].goto(x,y)

    move()

    for seg in segments:
        if seg.distance(head)<20:
            time.sleep(2)
            head.goto(0,0)
            head.direction = "stop"
            for seg in segments:
                seg.goto(1000, 1000)
            segments.clear()

            score = 0
            pen.clear()
            pen.write("Score : {} High Score : {}".format(score, high_score), align="center",
                      font=("Courier", 18, "normal"))


    time.sleep(delay)


wn.mainloop()
