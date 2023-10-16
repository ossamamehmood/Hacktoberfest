import cv2
import pickle
import numpy as np

class Park_classifier():
    """It just uses digital image process methods instead of deep learning to classify the parking space is empty or not.
    """
    
    def __init__(self, carp_park_positions_path:pickle, rect_width:int=None, rect_height:int=None):
        self.car_park_positions = self._read_positions(carp_park_positions_path) 
        self.rect_height = 48 if rect_height is None else rect_height
        self.rect_width = 107 if rect_width is None else rect_width
    
    
    def _read_positions(self, car_park_positions_path:pickle)->list:
        """It reads the pickle file for avoid any data corraption or mistake.

        Returns
        -------
        list
            List of the tuples which stores the top left point coordinates of rectangle of car park. Example Demostration :  [(x_1, y_1), ..., [x_n, y_n]]
        """

        car_park_positions = None
        try:
            car_park_positions = pickle.load(open(car_park_positions_path, 'rb'))
        except Exception as e:
            print(f"Error: {e}\n It raised while reading the car park positions file.")

        return car_park_positions

    def classify(self, image:np.ndarray, prosessed_image:np.ndarray,threshold:int=900)->np.ndarray:
        """It crops the already processed image into car park regions and classifies the parking space as empty or not according to threshold.

        Parameters
        ----------
        image : np.ndarray
            Image which is already processed by opencv digital image processing methods to prepare classify.
        threshold : int, optional
            It is the boundary value for classifying the alread processed images , by default 900

        Returns
        -------
        np.ndarray
            Image Which has drawn according to its class.
        """
        # Finding out the empty and occupied parking spaces and drawing them.
        empty_car_park = 0
        for x, y in self.car_park_positions:
            
            # defining the starting and ending points of the rectangle as cross line
            col_start, col_stop = x, x + self.rect_width
            row_start, row_stop = y, y + self.rect_height

            # cropping the car park areas form image
            crop=prosessed_image[row_start:row_stop, col_start:x+col_stop]
            
            # counting the number of pixel which below the threshold value reason of the expectation that previous image processing steps
            count=cv2.countNonZero(crop)
            
            # classifying accprding to the threshold value to updating counts and setting drawing params
            empty_car_park, color, thick = [empty_car_park + 1, (0,255,0), 5] if count<threshold else [empty_car_park, (0,0,255), 2]
                
            # drawing the rectangle on the image
            start_point, stop_point = (x,y), (x+self.rect_width, y+self.rect_height)
            cv2.rectangle(image, start_point, stop_point, color, thick)
        
        
        # drawing the legend rectengle where on the tıo left side of the image
        cv2.rectangle(image,(45,30),(250,75),(180,0,180),-1)

        ratio_text = f'Free: {empty_car_park}/{len(self.car_park_positions)}'
        cv2.putText(image,ratio_text,(50,60),cv2.FONT_HERSHEY_SIMPLEX,0.9,(255,255,255),2)
        
        return image
        

    def implement_process(self, image:np.ndarray)->np.ndarray:
        """It processes the image by applying opencv digital image processing methods.

        Parameters
        ----------
        image : np.ndarray
            Target image which will be processed to preapre classify.

        Returns
        -------
        np.ndarray
            Processed Image.
        """
        # defining the size of kernel matrix param
        kernel_size=np.ones((3,3),np.uint8)

        # gray scaling for reducing colour channel. 
        gray=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

        # gaussian bluring to reduce noise
        blur=cv2.GaussianBlur(gray, (3,3), 1)
        
        # implementing threashold to get forground object
        Thresholded=cv2.adaptiveThreshold(blur,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV,25,16)
        
        # bluring the image to reduce noise and normalize the pixel value gap which is caused by adaptive threshold
        blur=cv2.medianBlur(Thresholded, 5)

        # dilalting for increasing foreground object.
        dilate=cv2.dilate(blur,kernel_size,iterations=1)

        return dilate

class Coordinate_denoter():

    def __init__(self, rect_width:int=107, rect_height:int=48, car_park_positions_path:pickle="data/source/CarParkPos"):
        self.rect_width = rect_width
        self.rect_height = rect_height
        self.car_park_positions_path = car_park_positions_path
        self.car_park_positions = list()

    def read_positions(self)->list:
        """It reads the pickle file for avoid any data corraption or mistake.

        Returns
        -------
        list
            List of the tuples which stores the top left point coordinates of rectangle of car park. Example Demostration :  [(x_1, y_1), ..., [x_n, y_n]]
        """

        
        try:
            self.car_park_positions = pickle.load(open(self.car_park_positions_path, 'rb'))
        except Exception as e:
            print(f"Error: {e}\n It raised while reading the car park positions file.")

        return self.car_park_positions

    def mouseClick(self, events:int, x:int, y:int, flags:int, params:int):
        """It is the callback function for mouse click event according to opencv MouseCallBack structure.

        Parameters
        ----------
        events : int
            one of the cv2.MouseEventTypes constants
        x : int
            The x-coordinate of the mouse event.
        y : int
           The y-coordinate of the mouse event.
        flags : int
            one of the cv2.MouseEventFlags constants.
        params : int
            The optional parameter.
        """
        
        # add car park position to the list 
        if events==cv2.EVENT_LBUTTONDOWN:
            self.car_park_positions.append((x,y))
        
        # remove car park corresonding mouse click
        if events==cv2.EVENT_MBUTTONDOWN:

            # finding out end removing the corresponding label.
            for index, pos in enumerate(self.car_park_positions):
                
                # unpacking
                x1,y1=pos
                
                # setting the condition
                is_x_in_range= x1 <= x <= x1+self.rect_width
                is_y_in_range= y1 <= y <= y1+self.rect_height

                # checking the label is in the range
                if is_x_in_range and is_y_in_range:
                    self.car_park_positions.pop(index)

        # writing the label coordinates into the file
        with open(self.car_park_positions_path,'wb') as f:
            pickle.dump(self.car_park_positions,f)
        