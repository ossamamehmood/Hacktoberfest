print("***** WELCOME TO RANDOM NUMBER GUESSING GAME\n")
print("Please guess a random number less than 50 and win\n")

attempt = 0
import random
num = random.randint(1, 50)

while True:
    attempt += 1
    user_input = int(input("Please enter the number you guessed: "))
    
    if user_input < num:
        print("Please guess a higher value.\n")
    elif user_input > num:
        print("Please guess a lower value.\n")
    else:
        print("*** Congratulations! You WON ***\nYou guessed it in %d tries.\nCorrect number is %d" % (attempt, num))
        break
