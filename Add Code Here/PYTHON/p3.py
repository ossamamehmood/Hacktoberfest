#displaying Thumbnail
from PIL import Image
image = Image.open('e:/jpg/1.jpg')
box = (150, 200, 600, 600)
cropped_image = image.crop(box)
cropped_image.save('cropped_image.jpg')
image.show()
cropped_image.show()




