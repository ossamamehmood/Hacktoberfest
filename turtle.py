# Turtle Race Game using python

import turtle
import random

player_one = turtle.Turtle()
player_one.color("green")
player_one.shape("turtle")
player_one.penup()
player_one.goto(-200,100)
player_two = player_one.clone()
player_two.color("blue")
player_two.penup()
player_two.goto(-200,-100)

player_one.goto(300,60)
player_one.pendown()
player_one.circle(40)
player_one.penup()
player_one.goto(-200,100)
player_two.goto(300,-140)
player_two.pendown()
player_two.circle(40)
player_two.penup()
player_two.goto(-200,-100)

die = [1,2,3,4,5,6]

for i in range(20):
    if player_one.pos() >= (300,100):
            print(" Green Wins!")
            break
    elif player_two.pos() >= (300,-100):
            print(" Blue Wins!")
            break
    else:
            player_one_turn = input("[GREEN'S TURN]Press Enter to roll the die ")
            die_outcome = random.choice(die)
            print("The result of the die roll is: ")
            print(die_outcome)
            print("The number of steps will be: ")
            print(15*die_outcome)
            player_one.fd(15*die_outcome)
            player_two_turn = input("[BLUE'S TURN] Press Enter to roll the die ")
            d = random.choice(die)
            print("The result of the die roll is: ")
            print(d)
            print("The number of steps will be: ")
            print(15*d)
            player_two.fd(15*d)
