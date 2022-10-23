import cv2  
img = cv2.imread("d:/jpg/ali.jpg")  
(h, w) = img.shape[:2]  
center = (w / 2, h / 2)  

angle90 = 90  
angle180 = 180  
angle270 = 270  
scale = 1.0  

M = cv2.getRotationMatrix2D(center, angle90, scale)  
rotated90 = cv2.warpAffine(img, M, (h, w))  
      
M = cv2.getRotationMatrix2D(center, angle180, scale)  
rotated180 = cv2.warpAffine(img, M, (w, h))  
      
M = cv2.getRotationMatrix2D(center, angle270, scale)  
rotated270 = cv2.warpAffine(img, M, (h, w))  
      
cv2.imshow('Original Image', img)  
cv2.waitKey()  # waits until a key is pressed  
cv2.destroyAllWindows()  # destroys the window showing image  
      
cv2.imshow('Image rotated by 90 degrees', rotated90)  
cv2.waitKey()  # waits until a key is pressed  
cv2.destroyAllWindows()  # destroys the window showing imag  
      
cv2.imshow('Image rotated by 180 degrees', rotated180)  
cv2.waitKey()  # waits until a key is pressed  
cv2.destroyAllWindows()  # destroys the window showing image  
      
cv2.imshow('Image rotated by 270 degrees', rotated270)  
cv2.waitKey()  # waits until a key is pressed  
cv2.destroyAllWindows()  # destroys the window showing image  