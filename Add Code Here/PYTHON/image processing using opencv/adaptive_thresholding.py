import cv2
img = cv2.imread('TriptiVerma_IndiaThroughMyLens.jpg', 0)
img = cv2.resize(img, (320,225))
 # apply various adaptive thresholds
th1 = cv2.adaptiveThreshold(img, 255, \
                                  cv2.ADAPTIVE_THRESH_MEAN_C, \
                                  cv2.THRESH_BINARY, 7, 4)
th2 = cv2.adaptiveThreshold(img, 255, \
                                  cv2.ADAPTIVE_THRESH_GAUSSIAN_C, \
                                  cv2.THRESH_BINARY, 7, 4)
# display the images
cv2.imshow('ADAPTIVE_THRESHOLD_MEAN', th1)
cv2.imshow('ADAPTIVE_THRESHOLD_GAUSSIAN', th2)
cv2.waitKey(0)
cv2.destroyAllWindows()