from tkinter import *
from tkinter import messagebox
import math
root=Tk()
root.eval("tk::PlaceWindow . Center")

lb1=Label(text="Principal")
lb1.grid(row=0,column=0,sticky="W")
e1=Entry()
e1.grid(row=0,column=1)
e1.focus()

lb2=Label(text="Time")
lb2.grid(row=1,column=0,sticky="W")
e2=Entry()
e2.grid(row=1,column=1)

lb3=Label(text="Rate Of Interest")
lb3.grid(row=2,column=0,sticky="W")
e3=Entry()
e3.grid(row=2,column=1)


lb3=Label(text="Interest Payable")
lb3.grid(row=3,column=0,sticky="W")
lb4=Label(width=20)
lb4.grid(row=3,column=1)

def sic():
 p=float(e1.get())
 t=float(e2.get())
 r=float(e3.get())
 si=p*t*r/100
 lb4.config(text=si)

def cic():
 p=float(e1.get())
 t=float(e2.get())
 r=float(e3.get())
 ci=p*math.pow(1+r/100,t)
 lb4.config(text=ci)
 
 
def cf():
 e1.delete(0,'end')
 e2.delete(0,'end')
 e3.delete(0,'end')
 lb4.set=""
 e1.focus()

b1=Button(text="Simple Interest", width=15,command=sic)
b1.grid(row=4,column=0)

b2=Button(text="Compound Interest", width=15,command=cic)
b2.grid(row=4,column=1)

b3=Button(text="<-", width=15,command=cf)
b3.grid(row=5,column=0)

b4=Button(text="X", width=15,command=quit)
b4.grid(row=5,column=1)
mainloop()

