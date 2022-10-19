from tkinter import *
from tkinter import ttk
import tkinter.messagebox

root=Tk()
root.title("Tic Tac Toe")
#add Buttons
bu1=ttk.Button(root,text=' ')
bu1.grid(row=0,column=0,sticky='snew',ipadx=40,ipady=40)
bu1.config(command=lambda: ButtonClick(1))

bu2=ttk.Button(root,text=' ')
bu2.grid(row=0,column=1,sticky='snew',ipadx=40,ipady=40)
bu2.config(command=lambda: ButtonClick(2))

bu3=ttk.Button(root,text=' ')
bu3.grid(row=0,column=2,sticky='snew',ipadx=40,ipady=40)
bu3.config(command=lambda: ButtonClick(3))

bu4=ttk.Button(root,text=' ')
bu4.grid(row=1,column=0,sticky='snew',ipadx=40,ipady=40)
bu4.config(command=lambda: ButtonClick(4))

bu5=ttk.Button(root,text=' ')
bu5.grid(row=1,column=1,sticky='snew',ipadx=40,ipady=40)
bu5.config(command=lambda: ButtonClick(5))

bu6=ttk.Button(root,text=' ')
bu6.grid(row=1,column=2,sticky='snew',ipadx=40,ipady=40)
bu6.config(command=lambda: ButtonClick(6))

bu7=ttk.Button(root,text=' ')
bu7.grid(row=2,column=0,sticky='snew',ipadx=40,ipady=40)
bu7.config(command=lambda: ButtonClick(7))

bu8=ttk.Button(root,text=' ')
bu8.grid(row=2,column=1,sticky='snew',ipadx=40,ipady=40)
bu8.config(command=lambda: ButtonClick(8))

bu9=ttk.Button(root,text=' ')
bu9.grid(row=2,column=2,sticky='snew',ipadx=40,ipady=40)
bu9.config(command=lambda: ButtonClick(9))

playerturn=ttk.Label(root,text="   Player 1 turn!  ")
playerturn.grid(row=3,column=0,sticky='snew',ipadx=40,ipady=40)

playerdetails=ttk.Label(root,text="    Player 1 is X\n\n    Player 2 is O")
playerdetails.grid(row=3,column=2,sticky='snew',ipadx=40,ipady=40)

res=ttk.Button(root,text='Restart')
res.grid(row=3,column=1,sticky='snew',ipadx=40,ipady=40)
res.config(command=lambda: restartbutton())

a=1
b=0
c=0
def restartbutton():
    global a,b,c
    a=1
    b=0
    c=0
    playerturn['text']="   Player 1 turn!   "
    bu1['text']=' '
    bu2['text']=' '
    bu3['text']=' '
    bu4['text']=' '
    bu5['text']=' '
    bu6['text']=' '
    bu7['text']=' '
    bu8['text']=' '
    bu9['text']=' '
    bu1.state(['!disabled'])
    bu2.state(['!disabled'])
    bu3.state(['!disabled'])
    bu4.state(['!disabled'])
    bu5.state(['!disabled'])
    bu6.state(['!disabled'])
    bu7.state(['!disabled'])
    bu8.state(['!disabled'])
    bu9.state(['!disabled'])
    
#after getting result(win or loss or draw) disable button
def disableButton():
    bu1.state(['disabled'])
    bu2.state(['disabled'])
    bu3.state(['disabled'])
    bu4.state(['disabled'])
    bu5.state(['disabled'])
    bu6.state(['disabled'])
    bu7.state(['disabled'])
    bu8.state(['disabled'])
    bu9.state(['disabled'])


def ButtonClick(id):
    global a,b,c
    print("ID:{}".format(id))

    #for player 1 turn
    if id==1 and bu1['text']==' ' and a==1:
        bu1['text']="X"
        a=0
        b+=1
    if id==2 and bu2['text']==' ' and a==1:
        bu2['text']="X"
        a=0
        b+=1
    if id==3 and bu3['text']==' ' and a==1:
        bu3['text']="X"
        a=0
        b+=1
    if id==4 and bu4['text']==' ' and a==1:
        bu4['text']="X"
        a=0
        b+=1
    if id==5 and bu5['text']==' ' and a==1:
        bu5['text']="X"
        a=0
        b+=1
    if id==6 and bu6['text']==' ' and a==1:
        bu6['text']="X"
        a=0
        b+=1
    if id==7 and bu7['text']==' ' and a==1:
        bu7['text']="X"
        a=0
        b+=1
    if id==8 and bu8['text']==' ' and a==1:
        bu8['text']="X"
        a=0
        b+=1
    if id==9 and bu9['text']==' ' and a==1:
        bu9['text']="X"
        a=0
        b+=1
    #for player 2 turn
    if id==1 and bu1['text']==' ' and a==0:
        bu1['text']="O"
        a=1
        b+=1
    if id==2 and bu2['text']==' ' and a==0:
        bu2['text']="O"
        a=1
        b+=1
    if id==3 and bu3['text']==' ' and a==0:
        bu3['text']="O"
        a=1
        b+=1
    if id==4 and bu4['text']==' ' and a==0:
        bu4['text']="O"
        a=1
        b+=1
    if id==5 and bu5['text']==' ' and a==0:
        bu5['text']="O"
        a=1
        b+=1
    if id==6 and bu6['text']==' ' and a==0:
        bu6['text']="O"
        a=1
        b+=1
    if id==7 and bu7['text']==' ' and a==0:
        bu7['text']="O"
        a=1
        b+=1
    if id==8 and bu8['text']==' ' and a==0:
        bu8['text']="O"
        a=1
        b+=1
    if id==9 and bu9['text']==' ' and a==0:
        bu9['text']="O"
        a=1
        b+=1
        
    #checking for winner   
    if( bu1['text']=='X' and bu2['text']=='X' and bu3['text']=='X' or
        bu4['text']=='X' and bu5['text']=='X' and bu6['text']=='X' or
        bu7['text']=='X' and bu8['text']=='X' and bu9['text']=='X' or
        bu1['text']=='X' and bu4['text']=='X' and bu7['text']=='X' or
        bu2['text']=='X' and bu5['text']=='X' and bu8['text']=='X' or
        bu3['text']=='X' and bu6['text']=='X' and bu9['text']=='X' or
        bu1['text']=='X' and bu5['text']=='X' and bu9['text']=='X' or
        bu3['text']=='X' and bu5['text']=='X' and bu7['text']=='X'):
            disableButton()
            c=1
            tkinter.messagebox.showinfo("Tic Tac Toe","Winner is player 1")
    elif( bu1['text']=='O' and bu2['text']=='O' and bu3['text']=='O' or
        bu4['text']=='O' and bu5['text']=='O' and bu6['text']=='O' or
        bu7['text']=='O' and bu8['text']=='O' and bu9['text']=='O' or
        bu1['text']=='O' and bu4['text']=='O' and bu7['text']=='O' or
        bu2['text']=='O' and bu5['text']=='O' and bu8['text']=='O' or
        bu3['text']=='O' and bu6['text']=='O' and bu9['text']=='O' or
        bu1['text']=='O' and bu5['text']=='O' and bu9['text']=='O' or
        bu3['text']=='O' and bu5['text']=='O' and bu7['text']=='O'):
            disableButton()
            c=1
            tkinter.messagebox.showinfo("Tic Tac Toe","Winner is player 2")
    elif b==9:
            disableButton()
            c=1
            tkinter.messagebox.showinfo("Tic Tac Toe","Match is Draw.")

    if a==1 and c==0:
        playerturn['text']="   Player 1 turn!   "
    elif a==0 and c==0:
        playerturn['text']="   Player 2 turn!   "
            
root.mainloop()

