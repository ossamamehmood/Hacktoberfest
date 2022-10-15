print("Welcome to my computer quiz! ")
playing = input("Do you want to play quiz game? ")

if playing.lower() != "yes":
    quit()

print("okay let's play the game:) ")
score = 0


answer = input("What does RAM stand for?  ").lower()
if answer == "random access memory":
    print("correct!")
    score +=1
else:
    print("Incorrect!")

answer = input("What does CPU stand for?  ").lower()
if answer == "central processing unit":
    print("correct!")
    score +=1
else:
    print("Incorrect!")  

answer = input("What does GPU stand for?  ").lower()
if answer == "graphical processing unit":
    print("correct!")
    score +=1
else:
    print("Incorrect!")

answer = input("What does CLI stand for?  ").lower()
if answer == "command line interface":
    print("correct!")
    score +=1
else:
    print("Incorrect!")

answer = input("What does DSA stand for?  ").lower()
if answer == "data structure and algorithms":
    print("correct!")
    score +=1
else:
    print("Incorrect!")


if score >=5:
    print("congratulations😍 You got " + str(score) + " questions correct!")
    print("You got " + str((score/4) * 100) + "%.")
elif score >=3: 
    print(" You got " + str(score) + " questions correct!")
else:
    print("Oops! try again ☹ ")