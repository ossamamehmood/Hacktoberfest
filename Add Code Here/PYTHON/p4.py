#displaying Thumbnail
from PIL import Image
image = Image.open('d:/jpg/1.jpg')
logo = Image.open('d:/jpg/12.jpg')
image_copy = image.copy()
position = ((image_copy.width - logo.width), (image_copy.height - logo.height))
image_copy.paste(logo, position)
image_copy.save('pasted_image.jpg')
image_copy.show()