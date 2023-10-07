import os
import datetime

def create_diary_entry():
    now = datetime.datetime.now()
    date_string = now.strftime("%Y-%m-%d_%H-%M-%S")
    
    entry_filename = f"diary_{date_string}.txt"
    with open(entry_filename, "w") as file:
        print("Write your diary entry. Press Enter to save and exit.")
        while True:
            line = input()
            if not line:
                break
            file.write(line + "\n")

def view_diary_entries():
    entries = [entry for entry in os.listdir() if entry.startswith("diary_")]
    if not entries:
        print("No diary entries found.")
        return
    
    print("List of diary entries:")
    for i, entry in enumerate(entries, start=1):
        print(f"{i}. {entry}")
    
    choice = input("Enter the number of the entry you want to view: ")
    try:
        choice = int(choice)
        if 1 <= choice <= len(entries):
            with open(entries[choice - 1], "r") as file:
                print(f"\nDiary Entry - {entries[choice - 1]}:\n")
                print(file.read())
        else:
            print("Invalid entry number.")
    except ValueError:
        print("Invalid input. Please enter a valid entry number.")

def personal_diary():
    print("Welcome to your Personal Diary!")

    while True:
        print("\nMenu:")
        print("1. Create a New Diary Entry")
        print("2. View Diary Entries")
        print("3. Quit")

        choice = input("Enter your choice (1/2/3): ")

        if choice == "3":
            print("Goodbye! Thanks for using your Personal Diary.")
            break

        if choice == "1":
            create_diary_entry()
            print("Diary entry created successfully.")
        elif choice == "2":
            view_diary_entries()
        else:
            print("Invalid choice. Please choose a valid option (1/2/3).")

if __name__ == "__main__":
    personal_diary()
