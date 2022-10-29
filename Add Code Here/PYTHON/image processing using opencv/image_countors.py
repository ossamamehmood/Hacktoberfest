import cv2
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 1)
img = cv2.resize(img, (320,480))
# show original image
cv2.imshow('Original', img)
# binary thresholding
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
val,th = cv2.threshold(gray, 127,255,cv2.THRESH_BINARY)
# find contours
contours,_ = cv2.findContours(th, 
                               cv2.RETR_TREE,
                               cv2.CHAIN_APPROX_NONE)
# draw contours on original image
# arguments: image, contours list, index of contour, colour, thickness
cv2.drawContours(img, contours, -1, (0,0,255),1)
cv2.imshow('Contour', img)
cv2.waitKey(0)
cv2.destroyAllWindows() 