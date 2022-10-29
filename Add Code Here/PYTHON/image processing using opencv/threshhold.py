import cv2
# read an image in grayscale
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
img = cv2.resize(img, (320,225))
 # apply various thresholds
val, th1 = cv2.threshold(img, 110, 255, cv2.THRESH_BINARY)
val, th2 = cv2.threshold(img, 110, 255, cv2.THRESH_BINARY_INV)
val, th3 = cv2.threshold(img, 110, 255, cv2.THRESH_TRUNC)
val, th4 = cv2.threshold(img, 110, 255, cv2.THRESH_TOZERO)
val, th5 = cv2.threshold(img, 110, 255, cv2.THRESH_TOZERO_INV)
 # display the images
cv2.imshow('Original', img)
cv2.imshow('THRESH_BINARY', th1)
cv2.imshow('THRESH_BINARY_INV', th2)
cv2.imshow('THRESH_TRUNC', th3)
cv2.imshow('THRESH_TOZERO', th4)
cv2.imshow('THRESH_TOZERO_INV', th5)
cv2.waitKey(0)
cv2.destroyAllWindows()