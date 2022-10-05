import tkinter as tk
main_screen = tk.Tk()
main_screen.title("Currency Converter")
#Canvas is the window that gets created when we run the app
main_screen_canvas = tk.Canvas(main_screen, width = 400, height = 400,
bg="RoyalBlue4")
main_screen_canvas.pack()
#Label 1 is for naming the App
header = tk.Label(main_screen, text='CURRENCY CONVERTER')
header.config(font=('helvetica', 10, 'bold',
'underline'),bg='RoyalBlue4',fg='white')
main_screen_canvas.create_window(200, 20, window=header)

#Label 2 is for giving the text to entry field
currency_INR_label = tk.Label(main_screen, text='INR:')
currency_INR_label.config(font=('helvetica', 10,
'bold'),bg='RoyalBlue4',fg='white')
main_screen_canvas.create_window(140, 100, window=currency_INR_label)

#currency_INR_entry takes the amount
currency_INR_entry = tk.Entry(main_screen, width = 10, font=('helvetica', 10,
'bold'),bg='SkyBlue4',fg='white')
main_screen_canvas.create_window(200, 100, window=currency_INR_entry)

#Creating the remaining labels and entry
#dollar label creation
currency_dollar_label = tk.Label(main_screen,text="DOLLARS:")
currency_dollar_label.config(font=('helvetica', 10,
'bold'),bg='RoyalBlue4',fg='white')
main_screen_canvas.create_window(120, 300, window=currency_dollar_label)
#entry for dollar label
converted_currency = tk.StringVar()
currency_dollar_converted_entry = tk.Entry(main_screen, width = 10,
font=('helvetica', 10, 'bold'),bg='SkyBlue4',fg='white', textvariable =converted_currency)
main_screen_canvas.create_window(200, 300,window=currency_dollar_converted_entry)
#Function to convert our currency
def conversion():
     dollar = 77.54
     inr = currency_INR_entry.get()
     dollar_converted = round(float(inr)/dollar, 2)
     converted_currency.set(str(dollar_converted))
#convert_button which when clicked, makes the function conversion run
convert_button = tk.Button(text='Convert', command=conversion,font=('helvetica', 10, 'bold'),bg='navy blue',fg='white')
main_screen_canvas.create_window(200, 200, window=convert_button)
