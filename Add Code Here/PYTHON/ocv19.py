import cv2  
import numpy as np  
from matplotlib import pyplot as plt  
img = cv2.imread("d:\\jpg\\4n.jpg",1)  
kernel = np.ones((5,5),np.float32)/25 
blur = cv2.bilateralFilter(img,9,500,500)  
plt.subplot(121),plt.imshow(img),plt.title('Original')  
plt.xticks([]), plt.yticks([])  
plt.subplot(122),plt.imshow(blur),plt.title('Bilateral Filter')  
plt.xticks([]), plt.yticks([])  
cv2.imshow("Image",blur)  
cv2.waitKey()