#!/usr/bin/env python
# coding: utf-8

# ----------------------------------------GUI QUIZ GAME APP----------------------------------------------

# # Problem Statement

# + This is a standard quiz application that presents a questionnaire to the user, 
#   and allows them to answer the same, and displays the correct answer if they are wrong.
# + We will be developing a simple multiple-choice quiz in python with GUI using Tkinter.
# + Each test will display the final score of the user.
# + The application will have an account creation option, wherein some users can be appointed as Admins

# ## Importing required Libraries

from tkinter import *                    # tkinter library to show GUI screen of quiz.
from base64 import b64decode             # base64 library is used to decode json file.
import io                                # io library to manage file related input output.
import json                              # json library to load json files.
from tkinter import messagebox as mb     # messagebox is used to display result of quiz.


# ## Uploading JSON Data File


# base_file contains encoded json file.
base_file = "ewogICJxdWVzdGlvbiI6IFsKICAgICJRMS4gV2hhdCBJbmRpYW4gY2l0eSBpcyB0aGUgY2FwaXRhbCBvZiB0d28gc3RhdGVzPyIsCiAgICAiUTIuIFdoaWNoIGNpdHkgaXMgdGhlIGNhcGl0YWwgb2YgSW5kaWE/IiwKICAgICJRMy4gU21hbGxlc3QgU3RhdGUgb2YgSW5kaWE/IiwKICAgICJRNC4gV2hlcmUgaXMgVGFqIE1haGFsIExvY2F0ZWQ/IgogIF0sCiAgImFuc3dlciI6IFsKICAgIDEsCiAgICAyLAogICAgMywKICAgIDIKICBdLAogICJvcHRpb25zIjogWwoKICAgIFsiQ2hhbmRpZ2FyaCIsCiAgICAgICJLb2xrYXRhIiwKICAgICAgIkRlbGhpIiwKICAgICAgIkJhbmdsb3JlIgogICAgXSwKICAgIFsiSmFpcHVyIiwKICAgICAgIkRlbGhpIiwKICAgICAgIkNoZW5uYWkiLAogICAgICAiTXVtYmFpIgogICAgXSwKICAgIFsiUmFqYXN0aGFuIiwKICAgICAgIlB1bmphYiIsCiAgICAgICJHb2EiLAogICAgICAiQmloYXIiCiAgICBdLAogICAgWyJMdWNrbm93IiwKICAgICAgIkFncmEiLAogICAgICAiQmhvcGFsIiwKICAgICAgIkRlbGhpIgogICAgXQogIF0KfQ=="

# io_file contains Bytes.IO file after decoding base_file.
io_file = io.BytesIO(b64decode(base_file))

# json_file contains bytes file decoded using io_file.
json_file = io_file.getvalue()

# data_file contains json output file as a dictionary.
data_file = json.loads(json_file)


# QUIZ GAME Program

# Class Quiz_Question which contains methods to check answers, displaying quiz UI, and buttons for quit and next.
# a class to define the components of the GUI

class quiz_question:
    
    # Constructor of class quiz_question which sets the question count to 0, and initialize all the
    # other methoods to display the content and make all the functionalities available.
    
    def __init__(self):
        '''Constructor method'''
        # initially, set question number to 0
        self.question_no=0           
        # function to display title of quiz .
        self.title_function()        
        # function assigns question to the display_question function to update later.
        self.display_question()  
        # function to store selected option as integer value
        self.select_opt=IntVar()  
        # function to display radio button for the current question
        self.options=self.radio_button()
        # function to display options for the current question
        self.display_options()
        # function to display the button for next and quit.
        self.buttons()
        # no of questions
        self.data_size=len(questions_file)
        # keep a counter of correct answers
        self.correct_ans=0

        
    # This method is used to Display Title of GUI Screen
    def title_function(self):
        '''Displaying Title of QUIZ'''
    # title to be shown
        title = Label(gui, text="QUIZ APP", width=50, bg="magenta",fg="white", font=("ariel", 20, "bold"))
    # place of the title
        title.place(x=0, y=2)
        
        
    # This method shows the current Question on the screen
    def display_question(self):
        '''Function to display questions'''
        # setting the Question properties
        question_no_label = Label(gui, text=questions_file[self.question_no], width=60, font=('ariel' ,16, 'bold'), anchor= 'w' )
        #placing the option on the screen
        question_no_label.place(x=70, y=100)
    
    # This method displays options and clear them everytime before displaying next question
    def display_options(self):
        '''Function to display options for questions'''
        val=0
        # deselecting the options
        self.select_opt.set(0)
        # looping over the options to be displayed for the text of the radio buttons.
        for option in options_file[self.question_no]:
            self.options[val]['text']=option
            val+=1
        
    # This method is used to display the result and display correct and wrong answers
    def display_result(self):
        '''Function to display result after end of quiz'''
        # to calculate the wrong answers count and correct answers count.
        wrong_count = self.data_size - self.correct_ans
        correct = f"Correct: {self.correct_ans}"
        wrong = f"Wrong: {wrong_count}"
        # calculate the percentage of correct answers
        score = int(self.correct_ans / self.data_size * 100)
        result = f"Score: {score}%"
        # Shows a message box to display the result
        mb.showinfo("Result", f"{result}\n{correct}\n{wrong}")

    # This method checks the Answer after we click on Next.
    def check_ans(self, question_no):
        '''To check correct answers'''
        # checks for if the selected option is correct
        if self.select_opt.get() == answers_file[question_no]:
            # if the option is correct it return true
            return True


    # Method to check answer of question to increment correct answer count.
    # On pressing next button, it shows next question with options.
    # On last question, it shows result of quiz.
    def check_button_function(self):
        '''to check which button to call'''
        # Check if the answer is correct and if the answer is correct it increments the correct by 1
        if self.check_ans(self.question_no):
            self.correct_ans += 1
        # Move to next Question by incrementing the question_no counter
        self.question_no += 1

        # to check if the question_no size is equal to the data size
        # if it is correct then it displays the score
        if self.question_no==self.data_size:        
            end_button = Button(gui, text="QUIZ ENDED",command=self.check_button_function, width=10,bg="teal",fg="white",font=("ariel",16,"bold"))
            end_button.place(x=350,y=380)
            self.display_result()
        # destroys the GUI screen
            gui.destroy()
        
        # shows the next question
        else:
            self.display_question()
            self.display_options()

    # This method shows the two buttons on the screen.
    # The first one is the next_button which moves to next question
    # The second button is the exit button which is used to close the GUI without completing the quiz.
    def buttons(self):
        '''To show next and quit buttons'''
        # The first button is the Next button to move to the next Question
        next_button = Button(gui, text="NEXT",command=self.check_button_function,
        width=10,bg="teal",fg="white",font=("ariel",16,"bold"))
        # palcing the button on the screen
        next_button.place(x=350,y=380)
        # This is the second button which is used to Quit the GUI
        quit_button = Button(gui, text="QUIT", command=gui.destroy, width=5,bg="red", fg="white",font=("ariel",16," bold"))
        # placing the Quit button on the screen
        quit_button.place(x=700,y=50)


    
    # To display radio buttons at specified position
    def radio_button(self):
        '''Function to display radio buttons'''
        # initialize the list with an empty list of options
        q_list = []
        # position of the first option
        y_pos = 150
        # adding the options to the list
        while len(q_list) < 4:
            # setting the radio button properties
            radio_btn = Radiobutton(gui,text=" ",variable=self.select_opt, value = len(q_list)+1,font = ("ariel",14))
            # adding the button to the list
            q_list.append(radio_btn)
            # placing the button
            radio_btn.place(x = 100, y = y_pos)
            # incrementing the y-axis position by 40
            y_pos += 40
            
        # return the radio buttons
        return q_list


# To create a GUI Window for Quiz Game
gui = Tk()

# set the size of the GUI Window
gui.geometry("800x450")

# set the title of the Window
gui.title("GUI Quiz App")
# to set background color of window
gui.configure(bg='azure')
# get the data from the json file
# set the question, options, and answer files
questions_file = data_file['question']
options_file = data_file['options']
answers_file = data_file['answer']

# create an object of the Quiz_Question Class.
quiz = quiz_question()

# Start the GUI
gui.mainloop()

# END OF THE QUIZ PROGRAM