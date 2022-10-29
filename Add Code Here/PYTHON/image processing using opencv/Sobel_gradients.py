import cv2
import numpy as np
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
img = cv2.resize(img, (300,200))
# Sobel image gradient
vertical = np.uint8(np.absolute(cv2.Sobel(img,cv2.CV_64F, 1,0, ksize=1)))
horizon = np.uint8(np.absolute(cv2.Sobel(img,cv2.CV_64F, 0,1, ksize=1)))
# display the images
cv2.imshow('Vertical', vertical)
cv2.imshow('Horizontal', horizon)
Sobel = cv2.bitwise_or(vertical, horizon)
cv2.imshow('Sobel', Sobel)
cv2.waitKey(0)
cv2.destroyAllWindows() 