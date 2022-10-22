from PIL import Image
image = Image.open('e:/jpg/1.jpg')
image_rot_90 = image.rotate(90)
image_rot_90.save('image_rot_90.png')
image_rot_180 = image.rotate(180)
image_rot_180.save('image_rot_180.png')
image.show()
image_rot_90.show()