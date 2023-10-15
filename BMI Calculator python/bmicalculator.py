# Importing the libraries
from future.moves import tkinter
from tkinter import ttk
from PIL import Image, ImageTk

# creating an object
root = tkinter.Tk()

# setting title and geomerty
root.title("BMI Calculator")
root.geometry("470x580+300+200")

# background color for window
root.config(bg="lightgrey")


# BMI Calculation
def bmi():
    Height = float(h.get())
    Weight = float(w.get())
    m = Height / 100  # converting height into meter
    B = round(float(Weight / m ** 2), 1)  # calculating
    label.config(text=B)  # displaying

    # conditions
    if B <= 18.5:
        label1.config(text="Underweight")
    elif (B > 18.5) and (B <= 25):
        label1.config(text="Normal")
    elif (B > 25) and (B <= 30):
        label1.config(text="Overweight")
    else:
        label1.config(text="Health is at risk!\n Need to lose")


# Heading label
top = tkinter.Label(root, text="BMI CALCULATOR", font=("arial", 25, "bold"), width=25, bd=5, bg="white")
top.place(x=0, y=0)

# Bottom box
tkinter.Label(root, width=72, height=18, bg="lightcyan").pack(side="bottom")

# two boxes
box = tkinter.PhotoImage(file="bo.png")
tkinter.Label(root, image=box).place(x=20, y=100)
tkinter.Label(root, image=box).place(x=240, y=100)

# scale
scale = tkinter.PhotoImage(file="scale.png")
tkinter.Label(root, image=scale, bg="lightcyan").place(x=20, y=310)

# slider 1
current = tkinter.DoubleVar()


def get_current():
    return '{: .2f}'.format(current.get())


def slider_c(event):
    height.set(get_current())

    # resizing image according to the slider
    size = int(float(get_current()))
    img = (Image.open("man.png"))
    resize = img.resize((50, 10 + size))
    p = ImageTk.PhotoImage(resize)
    man.config(image=p)
    man.place(x=70, y=550 - size)
    man.image = p


# to change bg
style_h = ttk.Style()
style_h.configure("TScale", background="white")

# Getting slider on window
slider_h = ttk.Scale(root, from_=0, to=220, orient="horizontal", style="TScale", command=slider_c, variable=current)
slider_h.place(x=80, y=250)

# slider 2
current2 = tkinter.DoubleVar()


def get_current2():
    return '{: .2f}'.format(current2.get())


def slider_c2(event):
    weight.set(get_current2())


# to change bg
style_w = ttk.Style()
style_w.configure("TScale", background="white")

slider_w = ttk.Scale(root, from_=0, to=200, orient="horizontal", style="TScale", command=slider_c2, variable=current2)
slider_w.place(x=300, y=250)

# Entry widget for height
height = tkinter.StringVar()
weight = tkinter.StringVar()
h = tkinter.Entry(root, textvariable=height, width=5, font=("arial", 50), bg="white", fg="black", bd=0,
                  justify="center")
h.place(x=35, y=160)
height.set(get_current())

# Entry widget for weight
w = tkinter.Entry(root, textvariable=weight, width=5, font=("arial", 50), bg="white", fg="black", bd=0,
                  justify="center")
w.place(x=255, y=160)
weight.set(get_current2())

# man
man = tkinter.Label(root, bg="lightcyan")
man.place(x=70, y=530)

# button for report
tkinter.Button(root, text="Report", width=15, height=2, font=("Arial", 10, "bold"), bg="#1f6e68", fg="white",
               command=bmi).place(x=280, y=340)

# label widget for showing calculated BMI
label = tkinter.Label(root, font=("arial", 30, "bold"), bg="lightcyan", fg="black")
label.place(x=350, y=450)

# Label widget for showing message
label1 = tkinter.Label(root, font=("arial", 10, "bold"), bg="lightcyan", fg="black", width=50)
label1.place(x=200, y=500)

# event loop
root.mainloop()