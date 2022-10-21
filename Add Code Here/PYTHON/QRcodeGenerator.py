# QR Code generator

import pyqrcode
import png
from pyqrcode import QRCode

code = "https://github.com/dheerajrao20"

url = pyqrcode.create(code)
url.png("dheerajrao20.png", scale=6)
