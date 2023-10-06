import tkinter as tk
from tkinter import messagebox
import os

# Function to clear text entries
def clear_entries():
    name_entry.delete(0, 'end')
    father_name_entry.delete(0, 'end')
    cnic_entry.delete(0, 'end')
    rollno_entry.delete(0, 'end')
    dob_entry.delete(0, 'end')
    class_entry.delete(0, 'end')
    section_entry.delete(0, 'end')
    verify_cnic_entry.delete(0, 'end')

# Function to go back to the main page
def go_back():
    clear_entries()
    show_main_page()


# Function to check if a CNIC exists in the file
def is_cnic_exist(cnic_to_check):
    if not os.path.exists("user_data.txt"):
        return False
    with open("user_data.txt", "r") as file:
        for line in file:
            data = line.strip().split(',')
            if len(data) >= 3 and data[2] == cnic_to_check:
                return True
    return False

# Function to show the Sign Up page
def show_signup_page():
    main_page.pack_forget()
    signup_page.pack()

# Function to handle sign-up
def signup():
    name = name_entry.get()
    father_name = father_name_entry.get()
    cnic = cnic_entry.get()
    rollno = rollno_entry.get()
    dob = dob_entry.get()
    class_val = class_entry.get()
    section = section_entry.get()

    # Check if the CNIC is already in the file
    if is_cnic_exist(cnic):
        messagebox.showinfo("User Exists", "User with this CNIC already exists.")
    else:
        with open("user_data.txt", "a") as file:
            file.write(f"{name},{father_name},{cnic},{rollno},{dob},{class_val},{section}\n")
        messagebox.showinfo("Registration Successful", "User registered successfully!")
        clear_entries()
        show_main_page()

# Function to show the Verification page
def show_verification_page():
    main_page.pack_forget()
    verification_page.pack()

# Function to verify user by CNIC
def verify_user():
    cnic_to_verify = verify_cnic_entry.get()
    if is_cnic_exist(cnic_to_verify):
        user_details = get_user_details(cnic_to_verify)
        messagebox.showinfo("User Found", f"User Details:\n{user_details}")
    else:
        messagebox.showinfo("User Not Found", "User not found.")
    verify_cnic_entry.delete(0, 'end')

# Function to get user details by CNIC
def get_user_details(cnic_to_check):
    with open("user_data.txt", "r") as file:
        for line in file:
            data = line.strip().split(',')
            if data[2] == cnic_to_check:
                return f"Name: {data[0]}\nFather's Name: {data[1]}\nCNIC: {data[2]}\nRoll No: {data[3]}\nDate of Birth: {data[4]}\nClass: {data[5]}\nSection: {data[6]}"

# Function to show the main page
def show_main_page():
    signup_page.pack_forget()
    verification_page.pack_forget()
    main_page.pack()

# Create the main window
root = tk.Tk()
root.title("User Verification System")

root.geometry("800x800")
root.configure(bg="#f0f0f0")
# Create the main page
main_page = tk.Frame(root)

signup_button = tk.Button(main_page, text="Sign Up", command=show_signup_page)
signup_button.pack()

verify_button = tk.Button(main_page, text="Verify User", command=show_verification_page)
verify_button.pack()

# Create the Sign Up page
signup_page = tk.Frame(root)

name_label = tk.Label(signup_page, text="Name:")
name_label.pack()
name_entry = tk.Entry(signup_page)
name_entry.pack()

father_name_label = tk.Label(signup_page, text="Father's Name:")
father_name_label.pack()
father_name_entry = tk.Entry(signup_page)
father_name_entry.pack()

cnic_label = tk.Label(signup_page, text="CNIC:")
cnic_label.pack()
cnic_entry = tk.Entry(signup_page)
cnic_entry.pack()

rollno_label = tk.Label(signup_page, text="Roll No:")
rollno_label.pack()
rollno_entry = tk.Entry(signup_page)
rollno_entry.pack()

dob_label = tk.Label(signup_page, text="Date of Birth:")
dob_label.pack()
dob_entry = tk.Entry(signup_page)
dob_entry.pack()

class_label = tk.Label(signup_page, text="Class:")
class_label.pack()
class_entry = tk.Entry(signup_page)
class_entry.pack()

section_label = tk.Label(signup_page, text="Section:")
section_label.pack()
section_entry = tk.Entry(signup_page)
section_entry.pack()

signup_button = tk.Button(signup_page, text="Sign Up", command=signup)
signup_button.pack()

signup_back_button = tk.Button(signup_page, text="Back to Main", command=show_main_page)
signup_back_button.pack()

# Create the Verification page
verification_page = tk.Frame(root)

verify_label = tk.Label(verification_page, text="Enter CNIC to Verify:")
verify_label.pack()
verify_cnic_entry = tk.Entry(verification_page)
verify_cnic_entry.pack()

verify_button = tk.Button(verification_page, text="Verify", command=verify_user)
verify_button.pack()

verify_back_button = tk.Button(verification_page, text="Back to Main", command=show_main_page)
verify_back_button.pack()

# Show the main page initially
show_main_page()

# Start the GUI main loop
root.mainloop()
