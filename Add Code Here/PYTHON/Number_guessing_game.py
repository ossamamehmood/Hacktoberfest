#from number_guess_logo import logo
from random import randint
from replit import clear
    
def game():
    # print(logo)
    difficulty = input("Enter difficaulty level: 'easy' or 'hard' : ").lower()
    if difficulty == 'easy':
        guess = 10
    elif difficulty == 'hard':
        guess = 5
    else:
        print("Inavalid input! ")
    num = randint(1,100)
    while guess > 0:
        print(f"You have {guess} choices remaining!")
        user_choice = int(input("Enter the number: "))
        if user_choice > num:
            print("Too high!")
        elif user_choice < num:
            print("Too Low!")
        else:
            print(f"The correct number was: {num}")
            print("That's the correct choice!\nYou Won!")
            break
        guess -= 1
    else:
        print(f"The correct number was: {num}")
        print("Opps! You are out of choices\nYou lost!")
        
game()
while input("Do you want to play again 'y' or 'n' : ").lower() == 'y':
    clear()
    game()
