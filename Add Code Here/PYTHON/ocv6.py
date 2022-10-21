import cv2  
img = cv2.imread("e://jpg//01.jpg", 1)  
scale = 60 
width = int(img.shape[1] * scale / 100)  
height = int(img.shape[0] * scale / 100)  
dim = (width, height)  
resized = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)  
print('Resized Dimensions : ', resized.shape)  
cv2.imshow("image", img)  
cv2.imshow("Resized image", resized)  
cv2.waitKey()  
cv2.destroyAllWindows()  