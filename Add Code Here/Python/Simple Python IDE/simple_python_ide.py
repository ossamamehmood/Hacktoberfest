
# Simple Python IDE


# imported necessary library
from tkinter import *
import tkinter as tk
import tkinter.messagebox as mbox
from io import StringIO # for finding the output
import webbrowser

# created main window
start1 = Tk()
start1.title("Welcome to New Python IDE")  # set up the title and size.
start1.geometry('1000x700')

# ---------------------------------------------------------
frameCnt = 4
frames = [PhotoImage(file='Images/start1.gif',format = 'gif -index %i' %(i)) for i in range(frameCnt)]

cnt = 0.0
def update(ind):
    global cnt
    frame = frames[ind]
    if(cnt == 1.0):
        cnt = 0
    cnt = cnt + 0.2
    ind += int(cnt)
    if ind == frameCnt:
        ind = 0
    label.configure(image=frame)
    start1.after(100, update, ind)
label = Label(start1)
label.place(x = 10, y = 10)
start1.after(0, update, 0)

# defined exit_win function, to show a exit dialog box when tried to exit
def exit_win():
    if mbox.askokcancel("Exit", "Do you want to exit?"):
        start1.destroy()

# created a callback function to open linked web browser
def callback(url):
    webbrowser.open_new_tab(url)

# function for start button
def start1_des():
    f1 = Frame(start1, width=1000, height=700)
    f1.propagate(0)
    f1.pack(side='top')
    f1.configure(bg="light yellow")

    # top label
    top1 = Label(f1, text = "Write Your Python Code Here...", font=("Arial", 40), fg="brown", bg = "light yellow") # same way bg
    top1.place(x = 100, y = 10)

    # Taking input of code from TextArea
    code_text = tk.Text(f1,height = 20, width = 60, font=("Arial", 15), bg = "light blue",fg = "blue", borderwidth=3, relief="solid")
    code_text.place(x = 50, y = 110)

    # function defined to run the code
    def run_code():
        try:
            old_stdout = sys.stdout
            redirected_output = sys.stdout = StringIO()
            exec(code_text.get("1.0", END))
            sys.stdout = old_stdout
            mbox.showinfo("Output", redirected_output.getvalue())
        except SyntaxError:
            mbox.showinfo("Output", "SyntaxError: unexpected EOF while parsing")

    # functon to reset the code written
    def reset_code():
        code_text.configure(bg="light blue", fg="blue")
        code_text.delete("1.0", END)

    # function defined to change the mode of the code area to black
    def black_mode():
        code_text.configure(bg="gray", fg="white")

    # created a run button
    runb = Button(start1, text="RUN", command=run_code, font=("Arial", 25), bg="orange", fg="blue",borderwidth=3, relief="raised")
    runb.place(x=800, y=110)

    # created a black button
    blackb = Button(start1, text="BLACK", command=black_mode, font=("Arial", 25), bg="gray", fg="blue", borderwidth=3,relief="raised")
    blackb.place(x=785, y=220)

    # created a reset button
    resetb = Button(start1, text="RESET", command=reset_code, font=("Arial", 25), bg="light green", fg="blue", borderwidth=3,relief="raised")
    resetb.place(x=785, y=330)

    # created a learn button
    learnb = Button(start1, text="LEARN", command=lambda: callback("https://www.geeksforgeeks.org/python-programming-language/?ref=ghm"), font=("Arial", 25), bg="light green", fg="blue",borderwidth=3, relief="raised")
    learnb.place(x=785, y=440)

    # created a exit button
    exitb = Button(start1, text="EXIT", command=exit_win, font=("Arial", 25), bg="red", fg="blue",borderwidth=3, relief="raised")
    exitb.place(x=800, y=550)

    # bottom label
    bottom1 = Label(f1, text="Explore the new Python IDE", font=("Arial", 40), fg="blue",bg="light yellow")  # same way bg
    bottom1.place(x=50, y=610)


# created a start button
startb = Button(start1, text="START",command=start1_des,font=("Arial", 28), bg = "light green", fg = "blue", borderwidth=3, relief="raised")
startb.place(x =400 , y =620 )


start1.protocol("WM_DELETE_WINDOW", exit_win)
start1.mainloop()
