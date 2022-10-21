import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard

screen = Screen()
screen.setup(600, 600)
screen.tracer(0)

p = Player()
cm = CarManager()
sb = Scoreboard()

screen.listen()
screen.onkeypress(p.up, "Up")


game_over = False
while not game_over:
    time.sleep(0.1)
    screen.update()

    cm.car()
    cm.move()
    for seg in cm.segments:
        if seg.distance(p) < 25:
            sb.final_score()
            game_over = True

    finish = p.has_finished()
    if finish:
        sb.increase_score()
        cm.move_increase()

screen.exitonclick()