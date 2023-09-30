import  random
randNumber=random.randint(1,100)
print(randNumber)
guesses=0
userGuess=None

while(userGuess!=randNumber):
    userGuess=int(input("Enter your Guess : "))
    guesses+=1
    if(userGuess==randNumber):
        print("You guessed right :) ")
    else:
        if(userGuess>randNumber):
            print("Enter smaller number :( ")
        else:
            print("Enter larger number :) ") 

print(f"You guessed the number in {guesses} guesses")
with open("hiscore.txt","r") as f:
    hiscore=int(f.read())

if(guesses<hiscore):
    print("You have just broken the high score")
    with open("hiscore.txt","w") as f:
        f.write(str(guesses))