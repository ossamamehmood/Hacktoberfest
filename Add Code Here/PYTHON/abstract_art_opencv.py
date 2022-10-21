import cv2
import numpy as np

canvas = np.zeros((300, 300, 3), dtype='uint8')

for i in range(0, 25):
    r = np.random.randint(5, high=200)
    color = np.random.randint(0, high=256, size=(3, )).tolist()
    centre = tuple(np.random.randint(0, high=300, size=(2, )))

    cv2.circle(canvas, centre, r, color, -1)

cv2.imshow('abstract art', canvas)
cv2.waitKey(0)
