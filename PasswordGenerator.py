import random
import string

def generate_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

def password_generator():
    print("Welcome to the Password Generator program!")

    while True:
        try:
            length = int(input("Enter the desired password length (or 0 to quit): "))
            if length == 0:
                print("Goodbye! Thanks for using the Password Generator program.")
                break
            if length < 1:
                print("Please enter a valid password length (at least 1).")
                continue

            password = generate_password(length)
            print(f"Generated Password: {password}")
        except ValueError:
            print("Please enter a valid password length (at least 1) or 0 to quit.")

if __name__ == "__main__":
    password_generator()
