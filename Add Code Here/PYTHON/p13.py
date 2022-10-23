from PIL import Image, ImageDraw, ImageFont
im = Image.open('d:/jpg/01.jpg')
x=ImageDraw.Draw(im)
x.text((500,200),"library")
im.show()
im.save('libr.jpg')
