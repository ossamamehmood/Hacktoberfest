# Creating a basic numpad just like a nokia phone 

from tkinter import *
import itertools

# Let's create the Tkinter window
window = Tk()

# Then, you will define the size of the window in width(312) and height(324) using the 'geometry' method
window.geometry("312x324")

# In order to prevent the window from getting resized you will call 'resizable' method on the window
window.resizable(0, 0)

# Finally, define the title of the window
window.title("Numpad")


# Let's now define the required functions for the Calculator to function properly.
# 1. First is the button click 'btn_click' function which will continuously update the input field whenever a number is entered or any button is pressed it will act as a button click update.
def btn_click(item):
    global expression
    expression = expression + str(item)
    input_text.set(expression)


# 2. Second is the button clear 'btn_clear' function clears the input field or previous calculations using the button "C"
def btn_clear():
    global expression
    expression = ""
    input_text.set("")


expression = ""
# In order to get the instance of the input field 'StringVar()' is used

input_text = StringVar()
it = str(input_text)
# input_text = str()


letters_by_pad_number = {"3": "def", "9": "wxyz"}


# num = int(input("Enter num: "))

def number_to_text(val):
    message = ""
    digits = str(val)
    for digit, group in itertools.groupby(digits):
        letters = letters_by_pad_number[digit]
        presses_number = len(list(group))
        letter_index = (presses_number - 1) % len(letters)
        message += letters[letter_index]
    return message


# print(number_to_text(num))
result = (number_to_text(it))
# print(result)

# Once all the functions are defined then comes the main section where you will start defining the structure of the calculator inside the GUI.

# The first thing is to create a frame for the input field
input_frame = Frame(window, width=312, height=50, bd=0, highlightbackground="black", highlightcolor="black",
                    highlightthickness=1)
input_frame.pack(side=TOP)

# Then you will create an input field inside the 'Frame' that was created in the previous step. Here the digits or the output will be displayed as 'right' aligned


input_field = Entry(input_frame, font=('arial', 18, 'bold'), textvariable=result, width=50,
                    bg="#eee", bd=0, justify=RIGHT)
input_field.grid(row=0, column=0)
input_field.pack(ipady=10)  # 'ipady' is an internal padding to increase the height of input field
# Once you have the input field defined then you need a separate frame which will incorporate all the buttons inside it below the 'input field'
btns_frame = Frame(window, width=312, height=272.5, bg="grey")
btns_frame.pack()

# The first row will comprise of the buttons 'Clear (C)' and 'Divide (/)'
clear = Button(btns_frame, text="C", fg="black", width=32, height=3, bd=0, bg="#eee", cursor="hand2",
               command=lambda: btn_clear()).grid(row=0, column=0, columnspan=3, padx=1, pady=1)

# The second row will comprise of the buttons '7', '8', '9' and 'Multiply (*)'
seven = Button(btns_frame, text="7", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
               command=lambda: btn_click(7)).grid(row=1, column=0, padx=1, pady=1)
eight = Button(btns_frame, text="8", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
               command=lambda: btn_click(8)).grid(row=1, column=1, padx=1, pady=1)
nine = Button(btns_frame, text="9", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
              command=lambda: btn_click(9)).grid(row=1, column=2, padx=1, pady=1)

# The third row will comprise of the buttons '4', '5', '6' and 'Subtract (-)'
four = Button(btns_frame, text="4", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
              command=lambda: btn_click(4)).grid(row=2, column=0, padx=1, pady=1)
five = Button(btns_frame, text="5", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
              command=lambda: btn_click(5)).grid(row=2, column=1, padx=1, pady=1)
six = Button(btns_frame, text="6", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
             command=lambda: btn_click(6)).grid(row=2, column=2, padx=1, pady=1)

# The fourth row will comprise of the buttons '1', '2', '3' and 'Addition (+)'
one = Button(btns_frame, text="1", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
             command=lambda: btn_click(1)).grid(row=3, column=0, padx=1, pady=1)
two = Button(btns_frame, text="2", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
             command=lambda: btn_click(2)).grid(row=3, column=1, padx=1, pady=1)
three = Button(btns_frame, text="3", fg="black", width=10, height=3, bd=0, bg="#fff", cursor="hand2",
               command=lambda: btn_click(3)).grid(row=3, column=2, padx=1, pady=1)

# Finally, the fifth row will comprise of the buttons '0', 'Decimal (.)', and 'Equal To (=)'
zero = Button(btns_frame, text="0", fg="black", width=21, height=3, bd=0, bg="#fff", cursor="hand2",
              command=lambda: btn_click(0)).grid(row=4, column=0, columnspan=2, padx=1, pady=1)



window.mainloop()
