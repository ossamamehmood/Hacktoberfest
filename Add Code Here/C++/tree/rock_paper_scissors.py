import simpleguitk
import random

COMPUTER_SCORE = 0
HUMAN_SCORE = 0
human_choice = ""
computer_choice = ""

def choice_to_number(choice):
    return {'rock': 0, 'paper': 1, 'scissors': 2}[choice]


def number_to_choice(number):
    return {0: 'rock', 1: 'paper', 2:'scissors'}[number]


def random_computer_choice():
    return random.choice(['rock', 'paper', 'scissors'])


def choice_result(human_choice, computer_choice):
    global COMPUTER_SCORE
    global HUMAN_SCORE
    
    computer_choice_number = choice_to_number(computer_choice)
    human_choice_number = choice_to_number(human_choice)
    
    if human_choice == computer_choice:
        print("Tie")
        
    elif (human_choice_number - computer_choice_number) % 3 == 1:
        print("Computer wins!")
        COMPUTER_SCORE += 1
        
    else:
        print("Human wins!")
        HUMAN_SCORE += 1

def rock():
    global human_choice, computer_choice
    global HUMAN_SCORE, COMPUTER_SCORE
    
    human_choice = 'rock'
    computer_choice = random_computer_choice()
    choice_result(computer_choice, human_choice)

def paper():
    global human_choice, computer_choice
    global HUMAN_SCORE, COMPUTER_SCORE
    
    human_choice = 'paper'
    computer_choice = random_computer_choice()
    choice_result(computer_choice, human_choice)
    
def scissors():
    global human_choice, computer_choice
    global HUMAN_SCORE, COMPUTER_SCORE
    
    human_choice = 'scissors'
    computer_choice = random_computer_choice()
    choice_result(computer_choice, human_choice)
    
def draw(canvas):
    try:
        canvas.draw_text("You: " + human_choice, [10,40], 48, "Green")
        canvas.draw_text("Comp: " + computer_choice, [10,80], 48, "Red")
        
        canvas.draw_text("Human Score: " + str(HUMAN_SCORE), [10,150], 30, "Green")
        canvas.draw_text("Comp Score: " + str(COMPUTER_SCORE), [10,190], 30, "Red")
        
    except TypeError:
        pass

def play_rps():
    frame = simpleguitk.create_frame("Home", 300, 200)
    frame.add_button("Rock", rock)
    frame.add_button("Paper", paper)
    frame.add_button("Scissors", scissors)
    frame.set_draw_handler(draw)
    
    frame.start()
    
play_rps()
