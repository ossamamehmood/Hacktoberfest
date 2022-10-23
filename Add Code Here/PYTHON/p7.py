from PIL import Image, ImageFilter
#Open existing image
OriImage = Image.open('e:/jpg/02.jpg')
OriImage.show()
blurImage = OriImage.filter(ImageFilter.BLUR)
blurImage.show()
blurImage.save('e:/jpg/simBlurImage.jpg')