#Import required Image library
from PIL import Image, ImageFilter
OriImage = Image.open('e:/jpg/02.jpg')
OriImage.show()
gaussImage = OriImage.filter(ImageFilter.GaussianBlur(5))
gaussImage.show()
gaussImage.save('e:/jpg/gaussian_blur.jpg')