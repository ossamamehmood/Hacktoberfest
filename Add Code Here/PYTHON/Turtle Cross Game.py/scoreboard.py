from turtle import Turtle
FONT = ("Courier", 24, "normal")


class Scoreboard(Turtle):
    level = 1

    def __init__(self):
        super().__init__()
        self.penup()
        self.hideturtle()
        self.goto(-200, 250)
        self.write(f"Level: {self.level}", False, "center", FONT)

    def increase_score(self):
        self.level += 1
        self.clear()
        self.write(f"Level: {self.level}", False, "center", FONT)

    def final_score(self):
        self.goto(0, 0)
        self.clear()
        self.write(f"Game Over! Final score: {self.level}", False, "center", FONT)