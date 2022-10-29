import cv2
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
img = cv2.resize(img, (320,210))
# Apply Bilateral Filter
img1 = cv2.bilateralFilter(img,7,100,100)
# display the images
cv2.imshow('Original', img)
cv2.imshow('Bilateral', img1)
cv2.waitKey(0)
cv2.destroyAllWindows()