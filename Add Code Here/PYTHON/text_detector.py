import tkinter as tk
import os
import cv2 
import pytesseract
from tkinter.filedialog import askopenfilename

Root = tk.Tk()
Root.title("Text Detector")
Root.geometry('1000x600')

def ConvertText(Path):
    img = cv2.imread(Path)
    
    # Dowload OCR form Below link
    # https://osdn.net/projects/sfnet_tesseract-ocr-alt/downloads/tesseract-ocr-setup-3.02.02.exe/
    pytesseract.pytesseract.tesseract_cmd = r"D:\Tesseract-OCR\tesseract.exe"

    custom_config = r'--oem 3 --psm 6'
    text = pytesseract.image_to_string(img, config=custom_config)

    print(text)

    return text

def Upload():
    file = askopenfilename(defaultextension=".txt", filetypes=[
        ("JPEG", ".jpeg"), ("JPG", ".jpg"), ("PNG", ".png"), ("All Files", "*.*")])
    Current_path = os.path.abspath(file)
    print(ConvertText(Current_path))
    inputtxt.insert(1.0, ConvertText(Current_path))


inputtxt = tk.Text(Root, height=30, width=100)
inputtxt.pack()

printButton = tk.Button(Root, text='Upload an Image Here', command=Upload)
printButton.pack(ipadx=5, ipady=5, pady=30)

Root.mainloop()