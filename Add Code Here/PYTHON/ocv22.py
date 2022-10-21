import cv2  
import numpy as np  
from matplotlib import pyplot as plt  
img = cv2.imread("d:\\jpg\\4.jpg",0)  
retval, threshold = cv2.threshold(img, 62, 255, cv2.THRESH_BINARY)  
cv2.imshow("Original Image", img)  
cv2.imshow("Threshold",threshold)  
cv2.waitKey(0)  