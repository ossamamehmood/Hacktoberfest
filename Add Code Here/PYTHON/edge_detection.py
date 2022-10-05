import cv2
import numpy as np

def draw_contours(img, cnts):
    img = np.copy(img)
    img = cv2.drawContours(img, cnts, -1, (0, 255, 0), 2)
    return img


def draw_min_rect_circle(img, cnts):
    img = np.copy(img)

    for cnt in cnts:
        x, y, w, h = cv2.boundingRect(cnt)
        cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)

        min_rect = cv2.minAreaRect(cnt)
        min_rect = np.int0(cv2.boxPoints(min_rect))
        cv2.drawContours(img, [min_rect], 0, (0, 255, 0), 2) 

        (x, y), radius = cv2.minEnclosingCircle(cnt)
        center, radius = (int(x), int(y)), int(radius) 
        img = cv2.circle(img, center, radius, (0, 0, 255), 2) 
    return img


def draw_approx_hull_polygon(img, cnts):
    
    img = np.zeros(img.shape, dtype=np.uint8)

    cv2.drawContours(img, cnts, -1, (255, 0, 0), 2)  

    min_side_len = img.shape[0] / 32  
    min_poly_len = img.shape[0] / 16  
    min_side_num = 3 
    approxs = [cv2.approxPolyDP(cnt, min_side_len, True) for cnt in cnts] 
    approxs = [approx for approx in approxs if cv2.arcLength(approx, True) > min_poly_len]  
    approxs = [approx for approx in approxs if len(approx) > min_side_num] 
    
    cv2.polylines(img, approxs, True, (0, 255, 0), 2)  

    hulls = [cv2.convexHull(cnt) for cnt in cnts]
    cv2.polylines(img, hulls, True, (0, 0, 255), 2)  
    return img

def run():
    image = cv2.imread('Demo/test_edge_detection.jpg')
    thresh = cv2.Canny(image, 128, 256)

    thresh, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    """
    [[[-1 -1 -1 -1]]] :hierarchy  # cv2.Canny()
    
    [[[ 1 -1 -1 -1]
      [ 2  0 -1 -1]
      [ 3  1 -1 -1]
      [-1  2 -1 -1]]] :hierarchy  # cv2.threshold()
    """

    imgs = [
        image, thresh,
        draw_min_rect_circle(image, contours),
        draw_approx_hull_polygon(image, contours),
    ]

    for img in imgs:
        
        cv2.imshow("contours", img)
        cv2.waitKey(1943)


if __name__ == '__main__':
    run()
pass
