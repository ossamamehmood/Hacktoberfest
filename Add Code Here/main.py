import pyqrcode




# String which represent the QR code
s = " HELLO HACKTOBERFEST 2022"
# Generate QR code
url = pyqrcode.create(s)

# Create and save the png file naming "myqr.png"

url.png("my.png", scale = 8)
print(url.terminal(quiet_zone=1))
