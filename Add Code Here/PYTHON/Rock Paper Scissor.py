import random


rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

user_choice = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors."))
                     
# input_choice = [rock, paper, scissors]

computer_random_choice = random.randint(0,2)

print(f"Computer Choice is {computer_random_choice}")

if user_choice ==0 and computer_random_choice==2:
  print("You win")
  
elif user_choice<computer_random_choice:
  print("You loose")

elif computer_random_choice == user_choice:
  print('Draw')

else:
  print("You typed a invalid number, You loose")
