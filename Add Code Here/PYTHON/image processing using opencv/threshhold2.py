import cv2
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
cv2.imshow('Original', img)
img = cv2.resize(img,(3468,4624))
# Apply blur
img1 = cv2.blur(img,(3,3))
# display the images
cv2.imshow('Original', img)
cv2.imshow('Blur', img1)
cv2.waitKey(0)
cv2.destroyAllWindows()
