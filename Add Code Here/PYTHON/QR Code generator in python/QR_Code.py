import qrcode 
obj_QR = qrcode.QRCode(version=1, box_size=10, border=3)
Var = input("Enter to make QR Code:")
obj_QR.add_data(Var)
obj_QR.make(fit=True)
img = obj_QR.make_image(fill_color="Black", back_color="skyblue")
name = input("Enter the Name of your QR:")
img.save(name)
