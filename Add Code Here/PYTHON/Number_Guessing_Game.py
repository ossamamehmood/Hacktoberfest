import random

print("Welcome to the Number Guessing Game ! ")
print("I'm thinking of a number between 1 and 100 .")
choose = input("Choose a difficulty. Type 'easy'  or 'hard' : ")

number = random.randint(1,100)


def game(attempts):
    for i in range(attempts):
        print(f"You have {attempts -i} attempts remaining .")
        guess = int(input("Make a guess : "))
        if number == guess:
            print("You Win ")
            break
        elif number > guess:
            print("Too low")
        else:
            print("Too High ")

if choose == "easy":
    game(10)
else:
    game(5)