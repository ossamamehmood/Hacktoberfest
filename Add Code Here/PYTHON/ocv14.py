import numpy as np  
import cv2  
img = cv2.imread("d:/jpg/ali.jpg",1)  
cv2.line(img,(10,0),(150,150),(0,0,0),15)  
cv2.imshow('image',img)  
cv2.waitKey(0)  
cv2.destroyAllWindows()  
