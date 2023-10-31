contacts = []

def add_contact():
    name = input("Enter the contact's name: ")
    number = input("Enter the contact's phone number: ")
    contact = (name, number)
    contacts.append(contact)
    print("Contact added successfully.")

def list_contacts():
    if not contacts:
        print("No contacts found.")
    else:
        print("Your contacts:")
        for i, (name, number) in enumerate(contacts, start=1):
            print(f"{i}. {name}: {number}")

while True:
    print("\nOptions:")
    print("1. Add a contact")
    print("2. List contacts")
    print("3. Quit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_contact()
    elif choice == "2":
        list_contacts()
    elif choice == "3":
        print("Exiting the Contact Management App.")
        break
    else:
        print("Invalid choice. Please try again.")