import numpy as np  
import cv2  
img = cv2.imread("d:/jpg/ali.jpg",1)  
font = cv2.FONT_HERSHEY_SIMPLEX  
cv2.putText(img,'Hack Projects',(10,500),font,1,(255,255,255),2)
cv2.imshow('image',img)  
cv2.waitKey(0)  
cv2.destroyAllWindows()  
