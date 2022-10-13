from tkinter import *


def click(number):
    a = ent.get() + number
    ent.delete(0, END)
    ent.insert(0, a)


def clear():
    ent.delete(0, END)


def addition():
    global add, first_num
    a = ent.get()
    first_num = float(a)
    ent.delete(0, END)
    add = True


def substraction():
    global sub, first_num
    a = ent.get()
    first_num = float(a)
    ent.delete(0, END)
    sub = True


def multipication():
    global mul, first_num
    a = ent.get()
    first_num = float(a)
    ent.delete(0, END)
    mul = True


def division():
    global div, first_num
    a = ent.get()
    first_num = float(a)
    ent.delete(0, END)
    div = True


def enter():
    global add, sub, mul, div, first_num
    second_number = float(ent.get())
    ent.delete(0, END)
    if add:
        ent.insert(0, (first_num + second_number))
        add = False
    elif sub:
        ent.insert(0, (first_num - second_number))
        sub = False
    elif mul:
        ent.insert(0, (first_num * second_number))
        mul = False
    elif div:
        ent.insert(0, (first_num / second_number))
        div = False


first_num = 0
add = False
sub = False
mul = False
div = False

main = Tk()  # making a window using tkinter
main.title('Calculator')

ent = Entry(main, width=50, borderwidth=5)  # making input box
ent.grid(row=0, column=0, columnspan=4, pady=10)

button1 = Button(main, text='1', padx=35, pady=20,
                 command=lambda: click("1"))  # making buttons
button2 = Button(main, text='2', padx=35, pady=20, command=lambda: click("2"))
button3 = Button(main, text='3', padx=35, pady=20, command=lambda: click("3"))
button4 = Button(main, text='4', padx=35, pady=20, command=lambda: click("4"))
button5 = Button(main, text='5', padx=35, pady=20, command=lambda: click("5"))
button6 = Button(main, text='6', padx=35, pady=20, command=lambda: click("6"))
button7 = Button(main, text='7', padx=35, pady=20, command=lambda: click("7"))
button8 = Button(main, text='8', padx=35, pady=20, command=lambda: click("8"))
button9 = Button(main, text='9', padx=35, pady=20, command=lambda: click("9"))
button0 = Button(main, text='0', padx=35, pady=20, command=lambda: click("0"))
button_clear = Button(main, text='clear', padx=25, pady=20, command=clear)
button_add = Button(main, text='+', padx=35, pady=20, command=addition)
button_sub = Button(main, text='-', padx=35, pady=20, command=substraction)
button_mul = Button(main, text='*', padx=35, pady=20, command=multipication)
button_div = Button(main, text='/', padx=35, pady=20, command=division)
button_enter = Button(main, text='=', padx=35, pady=20, command=enter)


button1.grid(row=3, column=0, pady=5)
button2.grid(row=3, column=1, pady=5)
button3.grid(row=3, column=2, pady=5)

button4.grid(row=2, column=0, pady=5)
button5.grid(row=2, column=1, pady=5)
button6.grid(row=2, column=2, pady=5)

button7.grid(row=1, column=0)
button8.grid(row=1, column=1)
button9.grid(row=1, column=2)
button0.grid(row=4, column=0)

button_clear.grid(row=1, column=3)
button_add.grid(row=4, column=1)
button_sub.grid(row=4, column=2)
button_mul.grid(row=2, column=3)
button_div.grid(row=3, column=3)
button_enter.grid(row=4, column=3)


main.mainloop()  # calling the window we made
