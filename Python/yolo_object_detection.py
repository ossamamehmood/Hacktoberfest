import cv2 
import numpy as np

# Load Yolo

# Load the deep neural network in the system
net = cv2.dnn.readNet("yolov3.weights", "yolov3.cfg")

#load the classes from the coco dataset
classes = [] # 'person','bicycles' etc...
with open("coco.names", "r") as f:

    # put them simply in an array
    classes = [line.strip() for line in f.readlines()] # 'person','bicycles' etc...

# we need to get the final result which is why we use output_layers
# It gives you list of all layers used in a network. Like I am currently working with yolov3. It gives me a list of 254 layers.
layer_names = net.getLayerNames()
#It gives you the final layers number in the list from net.getLayerNames(). I think it gives the layers number that are unused (final layer). For yolov3, it gave me three number, 200, 227, 254. To get the corresponding indexes, we need to do layer_names[i[0] - 1]
output_layers = [layer_names[i[0] - 1] for i in net.getUnconnectedOutLayers()]
colors = np.random.uniform(0, 255, size=(len(classes), 3))

# Loading the  image so that we can do the operations on it
img = cv2.imread("room_ser.jpg") # image of a room

# image was large thus shrinking it
img = cv2.resize(img, None, fx=0.4, fy=0.4)
height, width, channels = img.shape

# Detecting objects
# blobs are the short images of the original image for 3 different channels Red,green and blue. there is not much difference for this particular image.
#True means change the channels
blob = cv2.dnn.blobFromImage(img, 0.00392, (416, 416), (0, 0, 0), True, crop=False)

#input
net.setInput(blob)
#output
outs = net.forward(output_layers)

# Showing informations on the screen
class_ids = []
confidences = []
boxes = []


for out in outs:
    for detection in out:
        scores = detection[5:]
        class_id = np.argmax(scores)
        confidence = scores[class_id]
        if confidence > 0.5:
            # Object detected
            center_x = int(detection[0] * width)
            center_y = int(detection[1] * height)
            w = int(detection[2] * width)
            h = int(detection[3] * height)

            # Rectangle coordinates
            x = int(center_x - w / 2)
            y = int(center_y - h / 2)

            boxes.append([x, y, w, h])
            confidences.append(float(confidence))
            class_ids.append(class_id)

indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.5, 0.4)
print(indexes)
font = cv2.FONT_HERSHEY_PLAIN
for i in range(len(boxes)):
    if i in indexes:
        x, y, w, h = boxes[i]
        label = str(classes[class_ids[i]])
        color = colors[class_ids[i]]
        cv2.rectangle(img, (x, y), (x + w, y + h), color, 2)
        cv2.putText(img, label, (x, y + 30), font, 3, color, 3)


cv2.imshow("Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()