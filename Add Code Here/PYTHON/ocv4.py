"""We can retrieve a pixel value by its row and column coordinates. It returns an array of blue, green, red values of the BGR image."""

import numpy as np  
import cv2  
img = cv2.imread("e://jpg//01.jpg",1)  
pixel = img[100,100]  
print(pixel)   

