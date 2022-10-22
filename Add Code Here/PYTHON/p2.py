from PIL import Image
image = Image.open('d:/jpg/1.jpg')
image.thumbnail((400, 400))
image.save('image_thumbnail.jpg')
print(image.size)
print(image.size)
image.show()
