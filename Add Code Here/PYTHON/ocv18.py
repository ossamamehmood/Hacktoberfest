import cv2    
import numpy    
img = cv2.imread("d:\\jpg\\4.jpg", 1)    
src=img 
dst = median = cv2.medianBlur(img,5)  
cv2.imshow("Gaussian Smoothing", numpy.hstack((src,dst)))    
cv2.waitKey(0)  
cv2.destroyAllWindows() 