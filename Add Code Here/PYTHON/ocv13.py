import numpy as np  
import cv2  
img = cv2.imread("d:/jpg/ali.jpg",1)  
cv2.ellipse(img, (250, 150), (80, 20), 5, 0, 360, (0,0,255), 1)  
cv2.imshow('image',img)  
cv2.waitKey(0)  
cv2.destroyAllWindows()  
