import cv2
from src.utils import Coordinate_denoter

def demostration():
    """It is the demonstration of the car_park_coordinate_generatorçpy .
    """

    
    # creating the Coordinate_generator instance for extracting the car park coordinates
    coordinate_generator=Coordinate_denoter()

    # reading and initialing the coordinates 
    coordinate_generator.read_positions()

    # setting the initial variables
    image_path = "data/source/example_image.png"
    rect_width, rect_height = coordinate_generator.rect_width, coordinate_generator.rect_height

    # serving the GUI window until user terminates it
    while True:
        
        # refreshing the image
        image =cv2.imread(image_path)

        # drawing the current car park coordinates
        for pos in coordinate_generator.car_park_positions: 
            
            # defning the boundaries
            start = pos
            end = (pos[0]+rect_width, pos[1]+rect_height)

            # drawing the rectangle into the image
            cv2.rectangle(image,start,end,(0,0,255),2)
        
        cv2.imshow("Image",image)

        # linking the mouse callback
        cv2.setMouseCallback("Image",coordinate_generator.mouseClick)

        # exit condition
        if cv2.waitKey(1) == ord("q"):
            break

    # re-allocating the sources
    cv2.destroyAllWindows()

if __name__ == "__main__":
    demostration()