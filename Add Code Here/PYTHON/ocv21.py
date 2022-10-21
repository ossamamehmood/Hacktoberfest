import cv2  
import numpy as np  
from matplotlib import pyplot as plt  
img = cv2.imread("d:\\jpg\\4n.jpg",1)  
kernel = np.ones((5,5),np.float32)/25  
dst = cv2.filter2D(img,-1,kernel)  
plt.subplot(121),plt.imshow(img),plt.title('Original')  
plt.xticks([]), plt.yticks([])  
plt.subplot(122),plt.imshow(dst),plt.title('Filter2D')  
plt.xticks([]), plt.yticks([])  
plt.show()  