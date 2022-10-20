from tkinter import *
import random


options = ["rock", "paper", "scissor"]


def replay():

    rock_button.config(state="normal")
    paper_button.config(state="normal")
    scissor_button.config(state="normal")

    display1.config(text="")
    display2.config(text="")
    display3.config(text="")


def quit():
    window.destroy()


def rock():
    computer_selection = random.choice(options)

    if computer_selection == "rock":
        display1.config(text="Your Choice : rock 🗻")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: Draw🤨")

    elif computer_selection == "paper":
        display1.config(text="Your Choice : rock 🗻")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: You lose🤣")

    elif computer_selection == "scissor":
        display1.config(text="Your Choice : rock 🗻")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: You won😪")

    rock_button.config(state="disabled")
    paper_button.config(state="disabled")
    scissor_button.config(state="disabled")


def paper():
    computer_selection = random.choice(options)

    if computer_selection == "paper":
        display1.config(text="Your Choice : paper 🧻")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: Draw🤨")

    elif computer_selection == "scissor":
        display1.config(text="Your Choice : paper 🧻")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: You lose🤣")

    elif computer_selection == "rock":
        display1.config(text="Your Choice : paper 🧻")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: You won😪")

    rock_button.config(state="disabled")
    paper_button.config(state="disabled")
    scissor_button.config(state="disabled")


def scissor():
    computer_selection = random.choice(options)

    if computer_selection == "scissor":
        display1.config(text="Your Choice : scissor ✂")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: Draw🤨")

    elif computer_selection == "rock":
        display1.config(text="Your Choice : scissor ✂")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: You lose🤣")

    elif computer_selection == "paper":
        display1.config(text="Your Choice : scissor ✂")
        display2.config(text=f"Computer's choice: {computer_selection}")
        display3.config(text="Result: You won😪")

    rock_button.config(state="disabled")
    paper_button.config(state="disabled")
    scissor_button.config(state="disabled")


window = Tk()
window.geometry("361x491")
window.title("Rock Paper Scissor")
window.configure(bg="#1E1F23")
canvas = Canvas(
    window,
    bg="#1E1F23",
    height=491,
    width=361,
    bd=0,
    highlightthickness=0,
    relief="ridge")
canvas.place(x=0, y=0)

background_img = PhotoImage(file=f"background.png")
background = canvas.create_image(
    180.5, 245.5,
    image=background_img)


replay_image = PhotoImage(file=f"img0.png")
quit_image = PhotoImage(file=f"img1.png")
scissor_image = PhotoImage(file=f"img2.png")
stone_image = PhotoImage(file=f"img3.png")
paper_image = PhotoImage(file=f"img4.png")
entry_image = PhotoImage(file=f"img_textBox0.png")


paper_button = Button(
    image=paper_image,
    borderwidth=0,
    highlightthickness=0,
    activebackground="#1E1F23",
    bg="#1E1F23",
    command=paper,
    relief="flat")

paper_button.place(
    x=143, y=145,
    width=76,
    height=67)

rock_button = Button(
    image=stone_image,
    borderwidth=0,
    highlightthickness=0,
    activebackground="#1E1F23",
    bg="#1E1F23",
    command=rock,
    relief="flat")

rock_button.place(
    x=51, y=145,
    width=76,
    height=67)


scissor_button = Button(
    image=scissor_image,
    borderwidth=0,
    highlightthickness=0,
    activebackground="#1E1F23",
    bg="#1E1F23",
    command=scissor,
    relief="flat")

scissor_button.place(
    x=235, y=145,
    width=76,
    height=67)

replay_button = Button(
    image=replay_image,
    borderwidth=0,
    highlightthickness=0,
    activebackground="#1E1F23",
    bg="#1E1F23",
    command=replay,
    relief="flat")

replay_button.place(
    x=85, y=368,
    width=191,
    height=50)


quit_button = Button(
    image=quit_image,
    borderwidth=0,
    highlightthickness=0,
    activebackground="#1E1F23",
    bg="#1E1F23",
    command=quit,
    relief="flat")

quit_button.place(
    x=85, y=426,
    width=191,
    height=50)


entry_bg = canvas.create_image(
    180.5, 294.0,
    image=entry_image)

display1 = Label(
    window,
    font=('arial', 12),
    bd=0,
    bg="#0D0D0F",
    fg="#EDC99F",
    highlightthickness=0)

display2 = Label(
    window,
    font=('arial', 12),
    bd=0,
    bg="#0D0D0F",
    fg="#EDC99F",
    highlightthickness=0)

display3 = Label(
    window,
    font=('arial', 12),
    bd=0,
    bg="#0D0D0F",
    fg="#EDC99F",
    highlightthickness=0)


display1.place(
    x=45.0, y=245,
)

display2.place(
    x=45.0, y=268,
)

display3.place(
    x=45.0, y=300,
)


window.resizable(False, False)
window.mainloop()
