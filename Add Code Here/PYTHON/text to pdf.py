import tkinter as tk
from tkinter import filedialog
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas

def text_to_pdf(text, output_filename):
    c = canvas.Canvas(output_filename, pagesize=letter)
    c.setFont("Helvetica", 12)

    y = 750  # Initial vertical position
    for line in text.split('\n'):
        c.drawString(50, y, line)
        y -= 20  # Adjust the vertical position
    c.save()

def browse_file():
    file_path = filedialog.asksaveasfilename(defaultextension=".pdf", filetypes=[("PDF files", "*.pdf")])
    if file_path:
        text_to_pdf(text_entry.get("1.0", "end-1c"), file_path)
        status_label.config(text=f"PDF saved as '{file_path}'")

root = tk.Tk()
root.title("Text to PDF Converter")

text_label = tk.Label(root, text="Enter text:")
text_label.pack(pady=10)

text_entry = tk.Text(root, height=10, width=50)
text_entry.pack()

convert_button = tk.Button(root, text="Convert to PDF", command=browse_file)
convert_button.pack(pady=10)

status_label = tk.Label(root, text="", fg="green")
status_label.pack()

root.mainloop()
