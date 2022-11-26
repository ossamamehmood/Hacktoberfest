from PIL import	 Image as  img
import qrcode

def generate_qrcode(text):
    qr = qrcode.QRCode(
        version = 1,
        error_correction = qrcode.constants. ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )

    qr.add_data(text)
    qr.make(fit=True)
    img = qr.make_image(fill_color="black", back_color="white")
    ## so you can save the file depends the name
    ## remove_spc_
    remove_spc_chr = ''.join(txt for txt in text if txt.isalnum())
    format_name = remove_spc_chr+".png"
    img.save(format_name)
    
url = input("Enter your url: ")
generate_qrcode(url)
