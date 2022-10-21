#marks report

from tkinter import *
root=Tk()
root.eval('tk::PlaceWindow . Center')

l1=Label(text="Sno")
l1.grid(row=0,column=0,sticky="W")
e1=Entry()
e1.grid(row=0,column=1)
e1.focus()

l2=Label(text="Sname")
l2.grid(row=1,column=0,sticky="W")
e2=Entry()
e2.grid(row=1,column=1)

l3=Label(text="Sclass")
l3.grid(row=2,column=0,sticky="W")
e3=Entry()
e3.grid(row=2,column=1)

l4=Label(text="Ssec")
l4.grid(row=3,column=0,sticky="W")
e4=Entry()
e4.grid(row=3,column=1)


l5=Label(text="M1")
l5.grid(row=4,column=0,sticky="W")
e5=Entry()
e5.grid(row=4,column=1)


l6=Label(text="M2")
l6.grid(row=5,column=0,sticky="W")
e6=Entry()
e6.grid(row=5,column=1)

l7=Label(text="M3")
l7.grid(row=6,column=0,sticky="W")
e7=Entry()
e7.grid(row=6,column=1)


l8=Label(text="M4")
l8.grid(row=7,column=0,sticky="W")
e8=Entry()
e8.grid(row=7,column=1)


l9=Label(text="M5")
l9.grid(row=8,column=0,sticky="W")
e9=Entry()
e9.grid(row=8,column=1)


l10=Label(text="M6")
l10.grid(row=9,column=0,sticky="W")
e10=Entry()
e10.grid(row=9,column=1)

l11=Label(text="Total")
l11.grid(row=10,column=0,sticky="W")
e11=Entry()
e11.grid(row=10,column=1)


l12=Label(text="Average")
l12.grid(row=11,column=0,sticky="W")
e12=Entry()
e12.grid(row=11,column=1)

l13=Label(text="Grade")
l13.grid(row=12,column=0,sticky="W")
e13=Entry()
e13.grid(row=12,column=1)


l14=Label(text="Pass/Fail")
l14.grid(row=13,column=0,sticky="W")
e14=Entry()
e14.grid(row=13,column=1)

def cmarks():
 e11.delete(0,'end')
 e12.delete(0,'end')
 e13.delete(0,'end')
 e14.delete(0,'end')
 m1=int(e5.get())
 m2=int(e6.get())
 m3=int(e7.get()) 
 m4=int(e8.get())
 m5=int(e9.get())
 m6=int(e10.get())
 tot=m1+m2+m3+m4+m5+m6
 e11.insert(0,tot)
 avg=tot/6
 e12.insert(0,avg)
 if(m1<35 or m2<35 or m3<35 or m4<35 or m5<35 or m6<35):
  e13.insert(0,'Fail')
  e14.insert(0,'No Grade')
 elif(avg>=65):
  e13.insert(0,'PASS')
  e14.insert(0,'A Grade')
 elif(avg<65 and avg>=45):
  e13.insert(0,'PASS')
  e14.insert(0,'B Grade')
 elif(avg<45):
  e13.insert(0,'PASS')
  e14.insert(0,'C Grade')

b1=Button(text="Calculate",command=cmarks)
b1.grid(row=15,column=0)

def cf():
 e1.delete(0,'end')
 e2.delete(0,'end')
 e3.delete(0,'end')
 e4.delete(0,'end')
 e5.delete(0,'end')
 e6.delete(0,'end')
 e7.delete(0,'end')
 e8.delete(0,'end')
 e9.delete(0,'end')
 e10.delete(0,'end')
 e11.delete(0,'end')
 e12.delete(0,'end')
 e13.delete(0,'end')
 e14.delete(0,'end')
 e1.focus()

b2=Button(text="Clear",command=cf)
b2.grid(row=15,column=1)

b3=Button(text="quit",command=quit)
b3.grid(row=15,column=2)

mainloop()
