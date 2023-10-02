# Implementation of Face Detection

import cv2

face_cap=cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
video_cap=cv2.VideoCapture(0) 
# 0 is used when camera has to be enabled at runtime.

while True :
    ret , video_data = video_cap.read()
    col = cv2.cvtColor(video_data,cv2.COLOR_BGR2GRAY)
    faces = face_cap.detectMultiScale(
        col,
        scaleFactor=1.2,
        minNeighbors=2,
        minSize=(30,30),
        flags=cv2.CASCADE_SCALE_IMAGE
    )
    for (x,y,w,h) in faces:
        cv2.rectangle(video_data,(x,y),(x+w,y+h),(0,255,0),2)
    cv2.imshow("video_live",video_data)

    # Remember that the camera popup, which would show up when the program
    # is executed, can only be closed using "a" because of ord("a")

    if cv2.waitKey(1) == ord("a") :
        break
video_cap.release()