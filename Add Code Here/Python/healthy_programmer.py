#Exercise 7
#Healthy Programmer
import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"

from pygame import mixer
from time import sleep
import datetime
from threading import *
#9am - 5pm {8 hrs - 480 minutes}
#3.5 litres - 3500 ml (17.5 = 18 glasses) {26 mins}
#eye - 30 minutes
def getdate():
    return datetime.datetime.now()
def writefile(fname):
    with open(fname,"at") as f:
        s=input("\nEnter What have you done: ")
        r=str(getdate())
        f.write('['+r+']')
        f.write('\t'+s+'\n')
        print("Data Stored Successfully")
class music_play(Thread):
    def run(self): 
        sleep(3)
        mixer.init()
        mixer.music.load(r"C:\Users\Win10\Desktop\python\sound.mp3")
        mixer.music.set_volume(0.7)
        mixer.music.play()  
        print("\nIt's Eye Exercise Time")
        try:
            writefile("Eye_Exercise.txt")
        except Exception as e:
            print(e)
        print("Press q to quit: ",end=" ")
        query=input(" ")
        if query=='q':
            mixer.music.stop()
        else:
            print("Please select a valid option")
class music_play1(Thread):
    def run(self):
        sleep(60)
        mixer.init()
        mixer.music.load(r"C:\Users\Win10\Desktop\virtualenv\song.mp3")
        mixer.music.set_volume(0.7)
        mixer.music.play()  
        print("\nIt's Physical Exercise Time")
        try:
            writefile("Physical_Exercise.txt")
        except Exception as e:
            print(e)
        print("Press q to quit: ",end=" ")
        query=input(" ")
        if query=='q':
            mixer.music.stop()
        else:
            print("Please select a valid option")
class music_play2(Thread):
    def run(self):
        sleep(15)
        mixer.init()
        mixer.music.load(r"C:\Users\Win10\Desktop\virtualenv\song.mp3")
        mixer.music.set_volume(0.7)
        mixer.music.play()  
        print("\nIt's Drinking Time")
        try:
            writefile("Drinking _Water.txt")
        except Exception as e:
            print(e)
        print("Press q to quit: ",end=" ")
        query=input(" ")
        if query=='q':
            mixer.music.stop()
        else:
            print("Please select a valid option")
if __name__=="__main__":
    print("Welcome to Healthy Programmer Alarm System")
    while True:
        now = datetime.datetime.now()
        if now.hour>=12 and now.hour<=23:
            print("Hi")
            t1 = music_play2()
            t2 = music_play()
            t3 = music_play1()
            t1.start()
            sleep(0.2)
            t2.start()
            sleep(0.2)
            t3.start()
            t1.join()
            t2.join()
            t3.join()
            
    print("Good Bye, Have a nice and healthy life")