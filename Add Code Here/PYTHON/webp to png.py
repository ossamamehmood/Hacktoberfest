from PIL import Image
import os

path = PATH HERE
a = os.listdir(path)
for i in a:
    im = Image.open(path + '/' + i ).convert("RGB")
    name = i.split('.')[0]
    im.save(path + '/' + f'{name}.jpg', 'jpeg')
    os.remove(path + '/' + i )