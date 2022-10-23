from PIL import Image
image = Image.open('e:/jpg/11.jpg')
greyscale_image = image.convert('L')
greyscale_image.save('greyscale_image.jpg')
image.show()
greyscale_image.show()
