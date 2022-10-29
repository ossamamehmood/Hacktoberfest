import cv2
img = cv2.imread("TriptiVerma_IndiaThroughMyLens.jpg",1)
img = cv2.resize(img, (320,210))
# Apply median blur
img1 = cv2.medianBlur(img,3)
# display the images
cv2.imshow('Original', img)
cv2.imshow('Median', img1)
cv2.waitKey(0)
cv2.destroyAllWindows()
