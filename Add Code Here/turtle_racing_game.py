from turtle import Turtle, Screen
from random import randint

s = Screen()
s.setup(width=800, height=400)

colors = ["red", "orange", "yellow", "green", "blue"]
y_positions = [-80, -40, 0, 40, 80]
turtles = []
is_race_on = False
user_guess = s.textinput("Guess the winner", "Guess which turtle will win. Type color: 'red', 'orange', 'yellow', 'green', 'blue'")

for index, color in enumerate(colors):
    t = Turtle(shape="turtle")
    t.color(color)  
    t.penup()
    t.goto(x=-380, y=y_positions[index])
    turtles.append(t)
    is_race_on = True

while is_race_on:
    for turtle in turtles:
        if turtle.xcor() > 375:
            winning_turtle = turtle.pencolor()
            
            if winning_turtle.lower() == user_guess.lower():
                print(f"You won, {winning_turtle} turtle won the race!")
            else:
                print(f"You lose, {winning_turtle} turtle won the race!, but you bet on {user_guess} turtle")
            is_race_on = False
        else:
            random_distance = randint(0, 10)
            turtle.forward(random_distance)

s.exitonclick()