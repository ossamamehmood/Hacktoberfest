#Import required Image library
from PIL import Image

#Create an Image Object from an Image
im = Image.open('d:/jpg/1.jpg')

#Display actual image
im.show()

#left, upper, right, lowe
#Crop
cropped = im.crop((1,2,300,300))

#Display the cropped portion
cropped.show()

#Save the cropped image
cropped.save('croppedBeach1.jpg')