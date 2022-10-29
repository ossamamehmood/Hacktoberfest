import cv2
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
img = cv2.resize(img, (320,210))
# Apply Gaussian blur
img1 = cv2.GaussianBlur(img,(5,5),2)
# display the images
cv2.imshow('Original', img)
cv2.imshow('Gaussian', img1)
cv2.waitKey(0)
cv2.destroyAllWindows()