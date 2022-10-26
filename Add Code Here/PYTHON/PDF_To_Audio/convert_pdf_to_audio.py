import pyttsx3
import PyPDF2

#Define the path to PDF file
pdf_link = "python-book.pdf"

# This opens the PDF file
book = open(pdf_link, 'rb')
pdfRead = PyPDF2.PdfFileReader(book, strict=False)
pages = pdfRead.numPages

full_content = ""

# This reads the PDF file
speaker = pyttsx3.init()
speaker.setProperty("rate", 140)

for num in range(pages):
    page = pdfRead.getPage(num)
    text = page.extractText()
    full_content += text

speaker.save_to_file(full_content, "myaudio.mp3")
speaker.runAndWait()