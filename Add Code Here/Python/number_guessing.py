import tkinter as tk
import random

# Generate a random number between 1 and 100
secret_number = random.randint(1, 100)
attempts = 0

def check_guess():
    global attempts
    attempts += 1
    guess = int(entry.get())
    if guess < secret_number:
        result_label.config(text="Higher!")
    elif guess > secret_number:
        result_label.config(text="Lower!")
    else:
        result_label.config(text=f"Congratulations! You guessed the number {secret_number} in {attempts} attempts.")
        guess_button.config(state=tk.DISABLED)
    entry.delete(0, tk.END)

# Create the main window
root = tk.Tk()
root.title("Number Guessing Game")

# Create a label
instruction_label = tk.Label(root, text="Guess the secret number (between 1 and 100):")
instruction_label.pack()

# Create an entry field
entry = tk.Entry(root)
entry.pack()

# Create a guess button
guess_button = tk.Button(root, text="Guess", command=check_guess)
guess_button.pack()

# Create a label for the result
result_label = tk.Label(root, text="")
result_label.pack()

# Start the GUI main loop
root.mainloop()
