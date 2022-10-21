import cv2
import glob

casca=cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

img=cv2.imread("soham.jpeg")
img=cv2.resize(img, (600, 720))

# Convert to grayscale for higher accuracy 
gray=cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

face=casca.detectMultiScale(gray, scaleFactor=1.05,
minNeighbors=5)

for x, y, w, h in face:
    img=cv2.rectangle(img, (x,y), (x+w,y+h), (0, 255, 0), 1)

cv2.imshow("Gray", img)
cv2.waitKey(0)
cv2.destroyAllWindows