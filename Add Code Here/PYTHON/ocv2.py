#copy image
import cv2  
img = cv2.imread("e://jpg//01.jpg",1)  
cv2.imwrite("e://jpg//002.jpg",img)  
cv2.waitKey() 

