#boxblur
from PIL import Image,ImageFilter
OriImage = Image.open('e:/jpg/02.jpg')
OriImage.show()
boxImage = OriImage.filter(ImageFilter.BoxBlur(5))
boxImage.show()
boxImage.save('e:/jpg/boxblur.jpg')