import random
num = random.randrange(10,20)
guessnum = int(input("Guess a number between 10 to 20: "))
while num!= guessnum:
    if guessnum < num:
        print("This number is too small")
        guessnum = int(input("Enter a number again: "))
    elif guessnum > num:
        print("This number is too big")
        guessnum = int(input("Enter a number again: "))
    else:
      break
print("you guessed it right.Hooray!!")