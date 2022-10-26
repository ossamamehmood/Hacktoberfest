select-site
logo
search

Disclosure: Hackr.io is supported by its audience. When you purchase through links on our site, we may earn an affiliate commission.



Top 10 Fun & Easy Python Projects for Beginners (with Code)

Posted in Python
Python Projects

Simran Kaur Arora
Last Updated 15 Sep, 2022
Share:
share-facebook share-twitter share-linkedin share-reddit share-hackrnews share-whatsapp
5 Comments
Table of Contents

AI, ML, and Data Science dominate many fields and industries today - all of them make heavy use of the Python programming language in some way or another. 


Becoming a master in Python can open many doors in your career and land in some of the best opportunities across the planet. No matter wherever you rate yourself in the Python skill, working on Python projects is a surefire way to boost your skills and build up your profile. While Python books and Python tutorials are helpful, nothing beats getting your hands dirty with actual coding.

We list several Python projects for beginners for you to challenge yourself and get better at Python coding.

 

Top 10 Python Project Ideas for Beginners
1. Mad Libs Generator 
This Python beginner project is a good start for beginners as it makes use of strings, variables, and concatenation. The Mad Libs Generator manipulates input data, which could be anything: an adjective, a pronoun, or verb. After taking in the input, the program takes the data and arranges it to build a story. This is a very cool Python project to try out if you’re new to coding.

Sample Code:

""" Mad Libs Generator

----------------------------------------

"""

#Loop back to this point once code finishes

loop = 1

while (loop < 10):

# All the questions that the program asks the user

noun = input("Choose a noun: ")

p_noun = input("Choose a plural noun: ")

noun2 = input("Choose a noun: ")

place = input("Name a place: ")

adjective = input("Choose an adjective (Describing word): ")

noun3 = input("Choose a noun: ")

#Displays the story based on the users input

print ("------------------------------------------")

print ("Be kind to your",noun,"- footed", p_noun)

print ("For a duck may be somebody's", noun2,",")

print ("Be kind to your",p_noun,"in",place)

print ("Where the weather is always",adjective,".")

print ()

print ("You may think that is this the",noun3,",")

print ("Well it is.")

print ("------------------------------------------")

# Loop back to "loop = 1"

loop = loop + 1
 

2. Number Guessing 
This project is a fun game that generates a random number in a certain specified range and the user must guess the number after receiving hints. Every time a user’s guess is wrong they are prompted with more hints to make it easier — at the cost of reducing the score.

The program also requires functions to check if an actual number is entered by the user, and finds the difference between the two numbers. 

Sample Code:

""" Number Guessing Game

----------------------------------------

"""

import random

attempts_list = []

def show_score():

if len(attempts_list) <= 0:

print("There is currently no high score, it's yours for the taking!")

else:

print("The current high score is {} attempts".format(min(attempts_list)))

def start_game():

random_number = int(random.randint(1, 10))

print("Hello traveler! Welcome to the game of guesses!")

player_name = input("What is your name? ")

wanna_play = input("Hi, {}, would you like to play the guessing game? (Enter Yes/No) ".format(player_name))

# Where the show_score function USED to be

attempts = 0

show_score()

while wanna_play.lower() == "yes":

try:

guess = input("Pick a number between 1 and 10 ")

if int(guess) < 1 or int(guess) > 10:

raise ValueError("Please guess a number within the given range")

if int(guess) == random_number:

print("Nice! You got it!")

attempts += 1

attempts_list.append(attempts)

print("It took you {} attempts".format(attempts))

play_again = input("Would you like to play again? (Enter Yes/No) ")

attempts = 0

show_score()

random_number = int(random.randint(1, 10))

if play_again.lower() == "no":

print("That's cool, have a good one!")

break

elif int(guess) > random_number:

print("It's lower")

attempts += 1

elif int(guess) < random_number:

print("It's higher")

attempts += 1

except ValueError as err:

print("Oh no!, that is not a valid value. Try again...")

print("({})".format(err))

else:

print("That's cool, have a good one!")

if __name__ == '__main__':

start_game()
 

3. Rock Paper Scissors
This rock paper scissors program uses a number of functions so this is a good way of getting that critical concept under your belt.

Random function: to generate rock, paper, or scissors. 
Valid function: to check the validity of the move.
Result function: to declare the winner of the round.
Scorekeeper: to keep track of the score.
The program requires the user to make the first move before it makes a move. The input could be a string or an alphabet representing either rock, paper or scissors. After evaluating the input string, a winner is decided by the result function and the score of the round is updated by the scorekeeper function. 

Sample Code:

""" Rock Paper Scissors

----------------------------------------

"""

import random

import os

import re

os.system('cls' if os.name=='nt' else 'clear')

while (1 < 2):

print ("\n")

print ("Rock, Paper, Scissors - Shoot!")

userChoice = input("Choose your weapon [R]ock], [P]aper, or [S]cissors: ")

if not re.match("[SsRrPp]", userChoice):

print ("Please choose a letter:")

print ("[R]ock, [S]cissors or [P]aper.")

continue

# Echo the user's choice

print ("You chose: " + userChoice)

choices = ['R', 'P', 'S']

opponenetChoice = random.choice(choices)

print ("I chose: " + opponenetChoice)

if opponenetChoice == str.upper(userChoice):

print ("Tie! ")

#if opponenetChoice == str("R") and str.upper(userChoice) == "P"

elif opponenetChoice == 'R' and userChoice.upper() == 'S':

print ("Scissors beats rock, I win! ")

continue

elif opponenetChoice == 'S' and userChoice.upper() == 'P':

print ("Scissors beats paper! I win! ")

continue

elif opponenetChoice == 'P' and userChoice.upper() == 'R':

print ("Paper beat rock, I win!")

continue

else:

print ("You win!")
 

4. Dice Roll Generator
This dice roll generator is a fairly simple program that makes use of the random function to simulate dice rolls. You can change the maximum value to any number, making it possible to simulate polyhedral dice used in many board games and roleplaying games.

Sample Code:

import random

#Enter the minimum and maximum limits of the dice rolls below

min_val = 1

max_val = 6

#the variable that stores the user’s decision

roll_again = "yes"

#The dice roll loop if the user wants to continue

while roll_again == "yes" or roll_again == "y":

print("Dices rolling...")

print("The values are :")

#Printing the randomly generated variable of the first dice

print(random.randint(min_val, max_val))

#Printing the randomly generated variable of the second dice

print(random.randint(min_val, max_val))

#Here the user enters yes or y to continue and any other input ends the program

roll_again = input("Roll the Dices Again?")
 

5. Binary Search Algorithm 
The binary search algorithm is a very important one, and requires you to create a list of numbers between 0 and an upper limit, with every succeeding number having a difference of 2 between them. 

When the user inputs a random number to be searched the program begins its search by dividing the list into two halves. First, the first half is searched for the required number and if found, the other half is rejected and vice versa. The search continues until the number is found or the subarray size becomes zero.

Sample Code:

# Recursive Binary Search algorithm in Python

def binarySearch(array, x, low, high):

if high >= low:

mid = low + (high - low)//2

# If found at mid, return the value

if array[mid] == x:

return mid

# Search the first half

elif array[mid] > x:

return binarySearch(array, x, low, mid-1)

# Search the second half

else:

return binarySearch(array, x, mid + 1, high)

else:

return -1

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

x = int(input("Enter a number between 1 and 10:"))

result = binarySearch(array, x, 0, len(array)-1)

if result != -1:

print("Element is present at position" + str(result))

else:

print("Element not found")
 



6. Calculator 
This project teaches you to design a graphical interface and is a good way to get familiar with a library like Tkinter. This library lets you create buttons to perform different operations and display results on the screen. 

Sample Code:

# Calculator

def addition ():

print("Addition")

n = float(input("Enter the number: "))

t = 0 #Total number enter

ans = 0

while n != 0:

ans = ans + n

t+=1

n = float(input("Enter another number (0 to calculate): "))

return [ans,t]

def subtraction ():

print("Subtraction");

n = float(input("Enter the number: "))

t = 0 #Total number enter

sum = 0

while n != 0:

ans = ans - n

t+=1

n = float(input("Enter another number (0 to calculate): "))

return [ans,t]

def multiplication ():

print("Multiplication")

n = float(input("Enter the number: "))

t = 0 #Total number enter

ans = 1

while n != 0:

ans = ans * n

t+=1

n = float(input("Enter another number (0 to calculate): "))

return [ans,t]

def average():

an = []

an = addition()

t = an[1]

a = an[0]

ans = a / t

return [ans,t]

# main...

while True:

list = []

print(" My first python program!")

print(" Simple Calculator in python by Malik Umer Farooq")

print(" Enter 'a' for addition")

print(" Enter 's' for substraction")

print(" Enter 'm' for multiplication")

print(" Enter 'v' for average")

print(" Enter 'q' for quit")

c = input(" ")

if c != 'q':

if c == 'a':

list = addition()

print("Ans = ", list[0], " total inputs ",list[1])

elif c == 's':

list = subtraction()

print("Ans = ", list[0], " total inputs ",list[1])

elif c == 'm':

list = multiplication()

print("Ans = ", list[0], " total inputs ",list[1])

elif c == 'v':

list = average()

print("Ans = ", list[0], " total inputs ",list[1])

else:

print ("Sorry, invilid character")

else:

break
 

7. Alarm Clock 
This Command Line Interface (CLI) Python application is a good step up for a beginner developer. More than just setting off an alarm, this program allows certain YouTube links to be added to a text file. When a user sets an alarm, the code picks a random video and starts playing it.

Sample Code:

""" Alarm Clock

----------------------------------------

"""

import datetime

import os

import time

import random

import webbrowser

# If video URL file does not exist, create one

if not os.path.isfile("youtube_alarm_videos.txt"):

print('Creating "youtube_alarm_videos.txt"...')

with open("youtube_alarm_videos.txt", "w") as alarm_file:

alarm_file.write("https://www.youtube.com/watch?v=anM6uIZvx74")

def check_alarm_input(alarm_time):

"""Checks to see if the user has entered in a valid alarm time"""

if len(alarm_time) == 1: # [Hour] Format

if alarm_time[0] < 24 and alarm_time[0] >= 0:

return True

if len(alarm_time) == 2: # [Hour:Minute] Format

if alarm_time[0] < 24 and alarm_time[0] >= 0 and \

alarm_time[1] < 60 and alarm_time[1] >= 0:

return True

elif len(alarm_time) == 3: # [Hour:Minute:Second] Format

if alarm_time[0] < 24 and alarm_time[0] >= 0 and \

alarm_time[1] < 60 and alarm_time[1] >= 0 and \

alarm_time[2] < 60 and alarm_time[2] >= 0:

return True

return False

# Get user input for the alarm time

print("Set a time for the alarm (Ex. 06:30 or 18:30:00)")

while True:

alarm_input = input(">> ")

try:

alarm_time = [int(n) for n in alarm_input.split(":")]

if check_alarm_input(alarm_time):

break

else:

raise ValueError

except ValueError:

print("ERROR: Enter time in HH:MM or HH:MM:SS format")

# Convert the alarm time from [H:M] or [H:M:S] to seconds

seconds_hms = [3600, 60, 1] # Number of seconds in an Hour, Minute, and Second

alarm_seconds = sum([a*b for a,b in zip(seconds_hms[:len(alarm_time)], alarm_time)])

# Get the current time of day in seconds

now = datetime.datetime.now()

current_time_seconds = sum([a*b for a,b in zip(seconds_hms, [now.hour, now.minute, now.second])])

# Calculate the number of seconds until alarm goes off

time_diff_seconds = alarm_seconds - current_time_seconds

# If time difference is negative, set alarm for next day

if time_diff_seconds < 0:

time_diff_seconds += 86400 # number of seconds in a day

# Display the amount of time until the alarm goes off

print("Alarm set to go off in %s" % datetime.timedelta(seconds=time_diff_seconds))

# Sleep until the alarm goes off

time.sleep(time_diff_seconds)

# Time for the alarm to go off

print("Wake Up!")

# Load list of possible video URLs

with open("youtube_alarm_videos.txt", "r") as alarm_file:

videos = alarm_file.readlines()

# Open a random video from the list

webbrowser.open(random.choice(videos))
