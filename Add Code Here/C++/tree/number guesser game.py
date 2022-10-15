i=0
print("Welcome to my game, here you have to guess a given number in maximum of 9 tries.\n")
while(i<10):
    a=int(input("Enter your guess here: "))
    i=i+1
    if a==21:
        print("Congratulations you've won the game.")
        print("No. of guesses used: ",i)
        break

    elif a>21:
        print("Your entered number is greater than the number. Try again")
        print("No. of guesses used: ",i)
        continue
    elif a<21:
        print("Your entered number is smaller than the number. Try again")
        print("No. of guesses used: ",i)
        continue
    
if i==10:
    print("GAME OVER the number was 21")




