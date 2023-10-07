# import all functions from tkinter module
from tkinter import *

# declare the global expression variable
exprsn = ""

# update expression in the text box
def onpress(number):
    global exprsn
    # adding to expression
    exprsn += str(number)
    # update the Tkinter variable
    eq.set(exprsn)

# to evaluate the  expression
def onPressEqualTo():
    # for handling that might raise exception
    global exprsn
    # to get the final result
    try:
        total = str(eval(exprsn))
        eq.set(total)
    except Exception as e:
        eq.set(" Error ")
        exprsn = ""
# to clear the entry box
def clear():
    global exprsn
    exprsn = ""
    eq.set("")

if __name__ == "__main__":
    # designing GUI window
    gui = Tk()

    # set up GUI window
    gui.configure(background="light grey")
    gui.title("Calculator")
    gui.geometry("290x220")

    # created  Tkinter variable and initialized using constructor
    eq = StringVar()

    exprsn_field = Entry(gui, textvariable=eq, width=40)
    exprsn_field.grid(columnspan=6, ipadx=1, ipady=2)

    # creating calculator Buttons
    button1 = Button(gui, text=' 1 ', fg='white', bg='black', command=lambda: onpress(1), height=2, width=9)
    button1.grid(row=2, column=0)
    button2 = Button(gui, text=' 2 ', fg='white', bg='black', command=lambda: onpress(2), height=2, width=9)
    button2.grid(row=2, column=1)
    button3 = Button(gui, text=' 3 ', fg='white', bg='black', command=lambda: onpress(3), height=2, width=9)
    button3.grid(row=2, column=2)
    button4 = Button(gui, text=' 4 ', fg='white', bg='black', command=lambda: onpress(4), height=2, width=9)
    button4.grid(row=3, column=0)
    button5 = Button(gui, text=' 5 ', fg='white', bg='black', command=lambda: onpress(5), height=2, width=9)
    button5.grid(row=3, column=1)
    button6 = Button(gui, text=' 6 ', fg='white', bg='black', command=lambda: onpress(6), height=2, width=9)
    button6.grid(row=3, column=2)
    button7 = Button(gui, text=' 7 ', fg='white', bg='black', command=lambda: onpress(7), height=2, width=9)
    button7.grid(row=4, column=0)
    button8 = Button(gui, text=' 8 ', fg='white', bg='black', command=lambda: onpress(8), height=2, width=9)
    button8.grid(row=4, column=1)
    button9 = Button(gui, text=' 9 ', fg='white', bg='black', command=lambda: onpress(9), height=2, width=9)
    button9.grid(row=4, column=2)
    button0 = Button(gui, text=' 0 ', fg='white', bg='black', command=lambda: onpress(0), height=2, width=9)
    button0.grid(row=5, column=1)
    bPlus = Button(gui, text=" + ", fg='white', bg='black', command=lambda: onpress("+"), height=2, width=9)
    bPlus.grid(row=2, column=3)
    bMinus = Button(gui, text=" - ", fg='white', bg='black', command=lambda: onpress("-"), height=2, width=9)
    bMinus.grid(row=3, column=3)
    bMulti = Button(gui, text=" * ", fg='white', bg='black', command=lambda: onpress("*"), height=2, width=9)
    bMulti.grid(row=4, column=3)
    bDivide = Button(gui, text=" / ", fg='white', bg='black', command=lambda: onpress("/"), height=2, width=9)
    bDivide.grid(row=5, column=3)
    bEqual = Button(gui, text=" = ", fg='white', bg='black', command=lambda: onPressEqualTo(), height=2, width=9)
    bEqual.grid(row=5, column=2)
    bClear = Button(gui, text="Clear", fg='white', bg='black', command=lambda: clear(), height=2, width=40)
    bClear.grid(columnspan=4)
    Point = Button(gui, text=" . ", fg='white', bg='black', command=lambda: onpress("."), height=2, width=9)
    Point.grid(row=5, column=0)
    gui.mainloop()

