# Install this Library  "pip install opencv-python"
import cv2
 
original_img = cv2.imread('img_500x326.jpg', 1)
water_mark = cv2.imread('watermark_500x326.jpg', 1)
 
img = cv2.addWeighted(water_mark, 0.1, original_img, 1.0, 0)
 
cv2.imwrite('Watermark.png',img)
 
cv2.waitKey(0)
 
cv2.destroyAllWindows()
