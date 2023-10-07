import random

def dice_roll_simulator():
    print("Welcome to the Dice Roll Simulator!")
    while True:
        try:
            sides = int(input("Enter the number of sides for the die (or 0 to quit): "))
            if sides == 0:
                print("Goodbye! Thanks for playing.")
                break
            if sides < 2:
                print("Please enter a valid number of sides (at least 2).")
                continue

            roll = random.randint(1, sides)
            print(f"You rolled a {roll}!")
        except ValueError:
            print("Please enter a valid number of sides (at least 2) or 0 to quit.")

if __name__ == "__main__":
    dice_roll_simulator()
