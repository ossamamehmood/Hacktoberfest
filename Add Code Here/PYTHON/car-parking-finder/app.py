# import cv2
# import numpy as np
# import pickle
# from src.utils import Park_classifier


# def demostration():
#     """It is a demonstration of the application.
#     """

#     # defining the params
#     rect_width, rect_height = 107, 48
#     carp_park_positions_path = "data/source/CarParkPos"
#     video_path = "data/source/carPark.mp4"

#     # creating the classifier  instance which uses basic image processes to classify
#     classifier = Park_classifier(carp_park_positions_path, rect_width, rect_height)

#     # Implementation of the classy
#     cap = cv2.VideoCapture(video_path)
#     while True:

#         # reading the video frame by frame
#         ret, frame = cap.read()

#         # check is there a retval
#         if not ret:break
        
#         # prosessing the frames to prepare classify
#         prosessed_frame = classifier.implement_process(frame)
        
#         # drawing car parks according to its status 
#         denoted_image = classifier.classify(image=frame, prosessed_image = prosessed_frame)
        
#         # displaying the results
#         cv2.imshow("Car Park Image which drawn According to  empty or occupied", denoted_image)
        
#         # exit condition
#         k = cv2.waitKey(1)
#         if k & 0xFF == ord('q'):
#             break
        
#         if k & 0xFF == ord('s'):
#             cv2.imwrite("output.jpg", denoted_image)

#     # re-allocating sources
#     cap.release()
#     cv2.destroyAllWindows()

# if __name__ == "__main__":
#     demostration()
