import cv2
import numpy as np
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
img = cv2.resize(img, (300,200))
# Laplacian image gradient
lap = np.uint8(np.absolute(cv2.Laplacian(img,cv2.CV_64F, ksize=1)))
# display the images
cv2.imshow('Original', img)
cv2.imshow('Lpalacian', lap)
cv2.waitKey(0)
cv2.destroyAllWindows() 