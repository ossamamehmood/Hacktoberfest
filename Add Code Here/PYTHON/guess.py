# import randint function from random library
from random import randint

# generate a random number between 1 and 100 and save it as myNum
playAgain = "y"

# main game loop which continues as long as the user wants to play again
while playAgain == "y":
    # generate random number between 1 and 100
    myNum = randint(1, 100)

    # counter for the number of guesses the user has made
    guess = 1

    # small introduction to the game
    print("### HI!, This is Guess the Number game. I hope you enjoy it. ###")
    print("#"*65, "\n")

    # check if the guessed number is within the valid range (1 to 100)
    while True:
        userGuess = int(input("\nEnter Your Guess: "))

        # validating user's input
        if 1 <= userGuess <= 100:
            # check if the user's input is equal to generated random number, and execute accordingly.
            if myNum == userGuess:
                print(f"\nBoom! Your score is {10 - (guess)}\nThe number was {myNum}")
                break

            # notify for a greater input
            elif userGuess < myNum:
                print(f"Enter a greater value. You got {10-guess} shots left.")

            # notify for a smaller input
            elif userGuess > myNum:
                print(f"Enter a smaller value. You got {10-guess} shots left.")
            guess += 1

            # if the user guesses 10 times, exit the game.
            if guess > 10:
                print("\nGame over! Your shots are over.")
                print(f"The number was {myNum}")
                break
        else:
            print("Please enter a valid input.")

    # prompt to ask in the user wants to play again
    playAgain = input("\nDo you want to play again?(y/n) ").lower()

print("\nThanks for playing with us. Enjoy your rest of the day!")
