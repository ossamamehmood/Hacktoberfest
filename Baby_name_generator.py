from  tkinter import*
import tkinter as tk
from tkinter import ttk
from tkinter.scrolledtext import ScrolledText
import names

# Added comment

def search():
    Gender=gender.get()
    Type=types.get()
    text.delete(0.0,END)
    if Gender=='Male'and Type=="Full Name":
        name= names.get_full_name(gender="male")
        text.insert('end',name)
    elif Gender=='Male' and Type=="First Name":
        name=names.get_first_name(gender="male")
        text.insert('end',name)
    elif Gender=='Male' and Type=="Last Name":
        name=names.get_last_name()
        text.insert('end',name)
    elif Gender=='Female' and Type=="Full Name":
        name=names.get_full_name(gender="female")
        text.insert('end',name)
    elif Gender=='Female' and Type=="First Name":
        name=names.get_first_name(gender="female")
        text.insert('end',name)
    elif Gender=='Female' and Type=="Last Name":
        name=names.get_last_name()
        text.insert('end',name)
    
root =Tk()
root.geometry('700x200')
root.title("Baby Name generator")


l = Label(root,text="Baby Name Generator App",font=('verdana',15,'bold'),bg="maroon",fg="white")
l.place(x=180, y=10)


l1= Label(root,text="Gender",font=('verdana',10,'bold'))
l1.place(x=50,y=60)
g=tk.StringVar()
gender=ttk.Combobox(root,width=13,textvariable=g, state="readonly",font=('verdana',10,'bold'),)
gender['values']=('Male','Female')
gender.place(x=50,y=90)
gender.current(0)

l2 = Label(root,text="Type",font=('verdana',10,'bold'))
l2.place(x=300, y=60)
t = tk.StringVar()
types = ttk.Combobox(root,width = 13, textvariable=t, state="readonly",font=('verdana',10,'bold'))
types['values']=('Full Name','First Name','Last Name')
types.place(x=300,y=90)
types.current(0)

button=Button(root,text="Search",font=('verdana',10,'bold'),command=search)
button.place(x=500,y=85)

text=ScrolledText(root,width=40,height=3)
text['font']=('verdana',10,'bold')
text.place(x=150, y=130)

root.mainloop()
