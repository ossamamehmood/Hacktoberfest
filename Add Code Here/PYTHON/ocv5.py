#image properties

import numpy as np  
import cv2  
img = cv2.imread("e://jpg//01.jpg",1)  
dimensions = img.shape
height = img.shape[0]  
width = img.shape[1]  
channels = img.shape[2]  
size1 = img.size  
print('Image Dimension    : ',dimensions)  
print('Image Height       : ',height)  
print('Image Width        : ',width)  
print('Number of Channels : ',channels)  
print('Image Size  :', size1)  
