import cv2  
import numpy as np  
from matplotlib import pyplot as plt  
img = cv2.imread("d:\\jpg\\4n.jpg",1)  
img_1 = cv2.boxFilter(img, 0, (1,1), img, (-1,-1), False, cv2.BORDER_DEFAULT)  
#This is using for display the image   
cv2.imshow('Image',img_1)  
cv2.waitKey()
cv2.destroyAllWindows()  
