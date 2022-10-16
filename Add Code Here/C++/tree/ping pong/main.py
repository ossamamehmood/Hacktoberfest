import turtle as t
import paddle as p
import ball
import time
from scoreboard import ScoreBoard




my_screen = t.Screen()
my_screen.setup(width=800,height=600)
my_screen.bgcolor("black")
my_screen.title("my ping pong game ")
my_screen.tracer(0)

fast = 0


#paddle challenge
total_paddle = []
r_paddle = p.Paddle((-350,0))

l_paddle = p.Paddle((350,0))

ball = ball.Ball()






my_screen.listen()

my_screen.onkey(r_paddle.goUp,"Up")
my_screen.onkey(r_paddle.goDown,"Down")
my_screen.onkey(l_paddle.goUp,"w")
my_screen.onkey(l_paddle.goDown,"s")

score = ScoreBoard()


is_game_on = True
while is_game_on:

    my_screen.update()
    ball.go()
    if ball.ycor() > 280  or ball.ycor() < -260:
        ball.bounce_y()


    if ball.distance(r_paddle) < 50 and ball.xcor() < -320 or ball.distance(l_paddle) < 50 and ball.xcor() > 320:
        ball.bounce_x()
        fast +=1

        ball.speed(fast)
    elif ball.xcor() < -380:

        score.l_ascore()
        ball.skrrt()
        score.update_score()

    elif ball.xcor() > 380:
        score.r_ascore()
        ball.skrrt()
        score.update_score()





    time.sleep(ball.move_speed)









my_screen.exitonclick()
