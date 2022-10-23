#resizing image
from PIL import Image
image = Image.open('d:/jpg/1.jpg')
new_image = image.resize((400, 400))
new_image.save('image_400.jpg')
print(image.size) 
print(new_image.size)
image.show()
new_image.show()


