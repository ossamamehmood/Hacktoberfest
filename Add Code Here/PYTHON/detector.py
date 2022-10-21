from pickle import TRUE
from tabnanny import check
from tkinter import Frame
from typing import Counter
import cv2
import time

ff=None
vid=cv2.VideoCapture(0)
# for internal camera

while True:
    
    check, frame = vid.read()
    print (check)
    print (frame)

    gray=cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray=cv2.GaussianBlur(gray, (21,21),0)



    if ff is None:
        ff=gray
        continue

    delta=cv2.absdiff(ff, gray)
    
    thres=cv2.threshold(delta, 30, 255, cv2.THRESH_BINARY)[1]
    thres=cv2.dilate(thres, None, iterations=2)


    (cnts,_)=cv2.findContours(thres.copy(),cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)


    for contour in cnts:
        if cv2.contourArea(contour)<1000:
            continue
    

        (x,y,w,h)=cv2.boundingRect(contour)
        cv2.rectangle(frame, (x,y),(x+w,y+h), (0,255,0), 1)




    
    cv2.imshow("Color Frameqq", frame)
    

    
    key=cv2.waitKey(1)

    # PRESS Q TO TERMINATE THE WINDOW 
    if key==ord('q'):
        break


vid.release()
cv2.destroyAllWindows
