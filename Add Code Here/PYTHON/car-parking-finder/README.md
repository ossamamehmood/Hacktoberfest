# Car-parking-Detection
- This project find outs the count of empty and occioped parking spaces in a car-parking-lot using through digital image processing techniques form opencv.

- Clone the repository.
```
git clone https://github.com/noorkhokhar99/car-parking-finder.git
```
- Goto the cloned folder.
```
cd car-parking-finder

```
- Upgrade pip with mentioned command below.
```
pip install --upgrade pip
```
- Install requirements with mentioned command below.
```
pip install -r requirements.txt
```
- Run the code with mentioned command below.

`app.py`

 
## Example Results


<p align="center">
<img src="data/results/example_result.png">





## Problem Defination
- finding out the empty parking spaces in a car-parking-lot aotomatically from servillance camera.

## solution
- Extracting the parking lot coordinates form the image by car_park_coordinate_generator.py script.
- Then use this coordinates to processing every car parking space individualy.
- Implementing digital iamge processing techniques to find out the empty and occupied parking spaces.
- drawing the reults into the image. 

## Used The Concepts
- OOP concepts
- Opencv High Level GUI Programming
- Opencv Basic Image Processing
- Doc String
- Python Type Annotation



### Controlling with the project
- labelling   __car park__
    - you can click left  mouse button. It will draw the its order.
- removing the label __car park__
    - you will do same thing above with mouse middle button instead of clicking left mouse button.

- __Exit__ from the project
    - just click __q__ button on your keyboard. (When your Operating System Selected the project window)
- __Saving__ the results
    - just click __s__ button on your keyboard. (When your Operating System Selected the project window)

## Note 
- CarParkingPos  is a pickle file which stores the empty car parking positions.  The car park areas represented as rectangle and they stored with coordinate of  its top left point.
