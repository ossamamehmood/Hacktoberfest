import tkinter as tk

def button_click(number):
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(tk.END, current + str(number))

def button_clear():
    entry.delete(0, tk.END)


def button_equal():
    try:
        result = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(tk.END, result)
    except Exception:
        entry.delete(0, tk.END)
        entry.insert(tk.END, "Error")

# Create the main window
window = tk.Tk()
window.title("Calculator")

# Create entry widget to display the numbers and results
entry = tk.Entry(window, width=30, borderwidth=5)
entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# Define the buttons
buttons = [
    ("7", 1, 0),
    ("8", 1, 1),
    ("9", 1, 2),
    ("/", 1, 3),
    ("4", 2, 0),
    ("5", 2, 1),
    ("6", 2, 2),
    ("*", 2, 3),
    ("1", 3, 0),
    ("2", 3, 1),
    ("3", 3, 2),
    ("-", 3, 3),
    ("0", 4, 0),
    (".", 4, 1),
    ("=", 4, 2),
    ("+", 4, 3),
]

# Create the buttons and assign their respective functions
for button_text, row, col in buttons:
    button = tk.Button(window, text=button_text, padx=20, pady=10, command=lambda text=button_text: button_click(text))
    button.grid(row=row, column=col)

# Create the clear button
clear_button = tk.Button(window, text="Clear", padx=20, pady=10, command=button_clear)
clear_button.grid(row=5, column=0, columnspan=2)


# Create the equal button
equal_button = tk.Button(window, text="=", padx=20, pady=10, command=button_equal)
equal_button.grid(row=5, column=2, columnspan=2)

# Start the main loop
window.mainloop()
