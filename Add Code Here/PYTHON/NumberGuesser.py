import random

def number_guesser():
    print("Welcome to the Number Guesser game!")
    print("I have selected a random number. Try to guess it.")
    
    lower_limit = 1
    upper_limit = 100
    secret_number = random.randint(lower_limit, upper_limit)
    
    attempts = 0
    
    while True:
        try:
            guess = int(input(f"Enter a number between {lower_limit} and {upper_limit}: "))
            attempts += 1
            
            if guess < lower_limit or guess > upper_limit:
                print(f"Please enter a number between {lower_limit} and {upper_limit}.")
                continue
            
            if guess < secret_number:
                print("Try a higher number.")
            elif guess > secret_number:
                print("Try a lower number.")
            else:
                print(f"Congratulations! You guessed the number {secret_number} in {attempts} attempts.")
                break
        except ValueError:
            print("Please enter a valid number.")

if __name__ == "__main__":
    number_guesser()
