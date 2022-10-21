from turtle import Turtle
import random

COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]


class CarManager:
    segments = []
    count = 0
    STARTING_MOVE_DISTANCE = 5
    MOVE_INCREMENT = 10

    def __init__(self):
        pass

    def car(self):
        self.count += 1
        if self.count % 6 == 0:
            y_cor = random.randint(-250, 250)
            car = Turtle()
            car.shape("square")
            car.shapesize(1, 2)
            car.color(random.choice(COLORS))
            car.penup()
            car.setheading(180)
            car.goto(300, y_cor)
            self.segments.append(car)

    def move(self):
        for seg in self.segments:
            seg.forward(self.STARTING_MOVE_DISTANCE)

    def move_increase(self):
        self.STARTING_MOVE_DISTANCE += self.MOVE_INCREMENT


