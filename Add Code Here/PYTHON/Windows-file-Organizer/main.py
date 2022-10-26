__author__ = "Ron Elgazar"
import tkinter 
from tkinter import messagebox
from tkinter import filedialog
import os
import sys
from datetime import datetime
import extensiondict
import  fileorganizer as fo
import webbrowser


class gui():
    def __init__(self):
        self.root = tkinter.Tk(className='file organizer')
        self.root.geometry("640x480")
        self.root.resizable(False, False)
        self.root.iconbitmap('icon.ico')
        self.sourcefoldertext = tkinter.StringVar()
        self.Targetfoldertext = tkinter.StringVar()
        self.sourcefoldertext.set("source folder")
        self.Targetfoldertext.set("Target folder")
        self.sourcelabel = tkinter.Label(self.root, textvariable=self.sourcefoldertext)
        self.Targetlabel = tkinter.Label(self.root, textvariable=self.Targetfoldertext)
        self.root.sourceFolder = ""
        self.root.TargetFolder = ""
        self.sourcebutton = tkinter.Button(self.root,text = "sourcefolder", width = 20, height = 3, command = self.chooseSourceDir)
        self.sourcebutton.width = 100
        self.Targetbutton = tkinter.Button(self.root,text = "Targetfolder", width = 20, height = 3, command = self.chooseTargetDir)
        self.Targetbutton.width = 100
        self.author = tkinter.Button(self.root,text="author's github",width = 12, height = 2,command=self.authorsiteloader)


        self.button = tkinter.Button(self.root,
                                text="start",
                                command=self.start)
        


        


#''' rendering on screen'''
        self.button.pack()
        self.sourcelabel.pack()
        self.Targetlabel.pack()
        self.Targetbutton.pack()
        self.sourcebutton.pack()
        self.author.pack()
#placing the widgets on screen
        self.button.place(x =300 ,y = 350)
        self.sourcebutton.place(x = 160,y = 240)
        self.Targetbutton.place(x =320 ,y = 240)
        self.sourcelabel.place(x=160,y= 200)
        self.Targetlabel.place(x=320,y=200)
        self.author.place(x=0,y=440)

        #main loop
        self.root.mainloop()

    #creates a new popupwindow with a console output and organizes the files 
    def start(self):
        self.popupscreen = tkinter.Tk(className="log")
        self.popupscreen.iconbitmap('icon.ico')
        self.popupB1 = tkinter.Button(self.popupscreen, text="Okay", command = self.popupscreen.destroy)
        self.popupscreen.geometry("640x480")
        self.popupscreen.wm_title("!")
        
        self.log_box_1 = tkinter.Text(self.popupscreen, borderwidth=3, relief="sunken")
        self.popupB1.pack()
        self.log_box_1.pack()

        for x in range(len(fo.cleandesk(self.root.sourceFolder,self.root.TargetFolder))):
            self.log_box_1.insert(tkinter.END, fo.cleandesk(self.root.sourceFolder,self.root.TargetFolder)[x])
#reading the fileorganizer.py output to write in the popup console for debuging        
        # with subprocess.Popen('python fileorganizer.py '+self.root.sourceFolder+ " "+self.root.TargetFolder, shell=True,stdout=subprocess.PIPE, bufsize=1, universal_newlines=True) as p:
            # for line in p.stdout:
                
        self.popupscreen.mainloop()

#opens My github account with the press of the self.authorsiteloader
    def authorsiteloader(self):
        webbrowser.open("https://github.com/ronelgazar")
# folder chooser
    def chooseSourceDir(self):
        self.root.sourceFolder =  filedialog.askdirectory(parent=self.root, initialdir= "/", title='Please select a directory')
        self.sourcefoldertext.set(self.root.sourceFolder)       

    def chooseTargetDir(self):
        self.root.TargetFolder =  filedialog.askdirectory(parent=self.root, initialdir= "/", title='Please select a directory')
        self.Targetfoldertext.set(self.root.TargetFolder) 

        
app=gui()