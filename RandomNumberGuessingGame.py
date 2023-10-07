import random

def guessing_game():
    secret_number = random.randint(1, 10)
    attempts = 0

    print("Welcome to the guessing game!")
    print("I've chosen a number between 1 and 10. Try to guess it.")

    while True:
        try:
            guess = int(input("Enter your guess: "))
            attempts += 1

            if guess < 1 or guess > 10:
                print("Please enter a number between 1 and 10.")
                continue

            if guess == secret_number:
                print(f"Congratulations! You guessed the number in {attempts} attempts.")
                break
            elif guess < secret_number:
                print("Try a higher number.")
            else:
                print("Try a lower number.")
        except ValueError:
            print("Please enter a valid number.")

if __name__ == "__main__":
    guessing_game()
