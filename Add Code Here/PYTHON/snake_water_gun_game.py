# Snake water gun
# Create a snake water gun game in Python! Search Snake water gun game in google if you need help on rules and how to play the game!
import random

i = 1
tie = 0
youwin = 0
comwin = 0
while i<=10:
    print("Choose one of the following: ")
    print("1. snake\n2. water\n3. gun")
    inp = input()
    com = random.choice(['snake', 'water', 'gun'])
   
    if inp == com:
        print(f"You choose: {inp} and Computer choose: {com}")
        print(f"Game Tie, Round {i}")
        tie += 1
    
    else:
        if inp == "snake" and com == "water":
            print(f"You choose: {inp} and Computer choose: {com}")
            print(f"You Win, Round {i}")
            youwin += 1
        elif inp == "snake" and com == "gun":
            print(f"You choose: {inp} and Computer choose: {com}")
            print(f"You Lose, Round {i}")
            comwin += 1
        elif inp == "water" and com == "snake":
            print(f"You choose: {inp} and Computer choose: {com}")
            print(f"You Win, Round {i}")
            youwin += 1
        elif inp == "water" and com == "gun":
            print(f"You choose: {inp} and Computer choose: {com}")
            print(f"You Win, Round {i}")
            youwin += 1
        elif inp == "gun" and com == "snake":
            print(f"You choose: {inp} and Computer choose: {com}")
            print(f"You Win, Round {i}")
            youwin += 1
        elif inp == "gun" and com == "water":
            print(f"You choose: {inp} and Computer choose: {com}")
            print(f"You Lose, Round {i}")
            comwin += 1
    i += 1
    
print(f"You win: {youwin} rounds, Computer win: {comwin} rounds and tie rounds: {tie} ")
