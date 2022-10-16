import random

randomNum=random.randint(1,100)


def Game():
    userGuess=None
    totalGuesses=0

    print("Guess a number between 1 & 100 ")

    while(userGuess != randomNum):
        userGuess=int(input("Enter your guess : "))
        totalGuesses += 1
        if (userGuess == randomNum):
            print("Your guess is right")
        else:
            if (userGuess<randomNum):
                print("Your guess is wrong, enter a larger number")
            else:    
                print("Your guess is wrong, enter a smaller number")
    print(f"You have completed in {totalGuesses} guesses")

    with open("best_score.txt") as f:
        best_score = int(f.read())   

    if (totalGuesses<best_score):
        print("New best rank : ", totalGuesses)
        with open("best_score.txt", "w") as f:
            f.write(str(totalGuesses))   

Game()