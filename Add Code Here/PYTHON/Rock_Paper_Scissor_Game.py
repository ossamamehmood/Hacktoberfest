import random
print("...rock...")
print("...paper...")
print("...scissors...")

player = input("\nEnter your choice from rock/paper/scissors:").lower()

computer = random.randint(1,3)
if computer == 1:
    computer = "rock"
if computer == 2:
    computer = "paper"
if computer == 3:
    computer = "scissors"

print(f"\n You played {player}")    
print(f"\nComputer plays {computer}")

if player == computer:
    print("\n Its a draw")
elif player == "rock":
    if computer == "paper":
        print("\n COM wins")
    elif computer == "scissors":
        print("\n You win") 
elif player == "paper":
    if computer == "rock":  
        print("\n You win")
    elif computer == "scissors":
         print("\n COM wins") 
elif player == "scissors":  
    if computer == "rock":
        print("\n COM wins")
    elif computer == "paper":
        print("\n You win")  
else:
    print("\nSomething went wrong") 
