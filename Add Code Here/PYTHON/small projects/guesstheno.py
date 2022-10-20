import random

def guess():
    pass
# def guess(x):
    random_number = random.randint(1,30)
    guess = 0
    while guess != random_number:
        guess = int(input(f"guess a number between 1 and 30: "))
        if guess < random_number:
            print("too low")
        elif guess > random_number:
            print("too high")

    print(f"guessed the number {random_number} corrrrrrrrectly")


guess()
# guess(x)


# computer guesses our number -- needs improvement

def comp_guess(x):
    low = 1
    high = x
    feed = ""
    while feed != "c":
        if low != high:
            guess = random.randint(low, high)
        else:
            guess=low
        input(f"is {guess} too high (h), too low(l) or correct(c)?").lower()
        if feed == "h":
            high = guess-1
        elif feed == "l":
            low = guess+1
    print("yay")

comp_guess(1000)
            
