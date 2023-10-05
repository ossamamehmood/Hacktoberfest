from tkinter import*

def sub():
	n1,n2= int(e1.get()),int(e2.get())
	res=n1-n2
	r.set(res)

def add():
	n1,n2= int(e1.get()),int(e2.get())
	res=n1+n2
	r.set(res)
	
def multiply():
	n1,n2= int(e1.get()),int(e2.get())
	res=n1*n2
	r.set(res)
	
def divide():
	n1,n2= int(e1.get()),int(e2.get())
	res=n1/n2
	r.set(res)
	
def clear():
	res=' '
	e1.delete(0,END)
	e2.delete(0,END)
	r.set(res)
	
master=Tk()
master.geometry('400x400')
r=StringVar()
l=Label(master,text='-:Calculator:-')
l1=Label (master, text='first number :')
l2=Label (master, text='second number :')
l3=Label (master, text='Result :')

e1=Entry(master)
e2=Entry(master)
result=Label (master,text='',textvariable=r)

b1=Button(master,text='-',fg='blue',bg='white',command=sub)
b2=Button(master,text='+',fg='red',bg='white',command=add)
b3=Button(master,text='*',fg='black',bg='white',command=multiply)
b4=Button(master,text='/',fg='olive',bg='white',command=divide)
b5=Button(master,text='clear',command=clear)

l.grid(column=1,row=0)

l1.grid(column=0,row=1)
e1.grid(column=1,row=1)

l2.grid(column=0,row=2)
e2.grid(column=1,row=2)

l3.grid(column=0,row=3)
result.grid(column=0,row=4)

b1.grid(column=0,row=5)
b2.grid(column=1,row=5)
b3.grid(column=0,row=6)
b4.grid(column=1,row=6)
b5.grid(column=2,row=6)

master.mainloop()
