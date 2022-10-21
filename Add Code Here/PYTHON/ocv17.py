import numpy as np  
import cv2  
im = cv2.imread("d:\\jpg\\ali.jpg") 
cv2.imshow('Blurred Image', cv2.blur(im, (100,100)))  
cv2.waitKey(0)  
cv2.destroyAllWindows()  