import random

def generate_random_number():
    """
    Generates and prints a random number between 1 and 100.
    """
    random_number = random.randint(1, 100)
    print(f"Random number: {random_number}")

if __name__ == "__main__":
    generate_random_number()
  
