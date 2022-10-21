#largest of 3 numbers
 
from tkinter import *
from tkinter import messagebox
root=Tk()
root.eval('tk::PlaceWindow . center')

l1=Label(text="A")
l1.grid(row=0,column=0)
e1=Entry()
e1.grid(row=0,column=1)
e1.focus()

l2=Label(text="B")
l2.grid(row=1,column=0)
e2=Entry()
e2.grid(row=1,column=1)

l3=Label(text="C")
l3.grid(row=2,column=0)
e3=Entry()
e3.grid(row=2,column=1)

def chkbg():
 a=int(e1.get())
 b=int(e2.get())
 c=int(e3.get())
 if(a>b and a>c):
  messagebox.showinfo("BIG","a is big")
  l1.config(text="a is big")
 elif(b>a and b>c):
  messagebox.showinfo("BIG","b is big")
  l1.config(text="b is big")
 else:
  messagebox.showinfo("BIG","c is big")
  l1.config(text="c is big")
 

def cf():
 e1.delete(0,'end')
 e2.delete(0,'end')
 e3.delete(0,'end')
 l1.config(text="")
 e1.focus()

b1=Button(text="check",width=10, command=chkbg)
b1.grid(row=3,column=0)

b2=Button(text="<-",width=10, command=cf)
b2.grid(row=3,column=1)

b3=Button(text="X",width=10, command=quit)
b3.grid(row=3,column=2)

l1=Label(text="")
l1.grid(row=4,column=1)
mainloop()




