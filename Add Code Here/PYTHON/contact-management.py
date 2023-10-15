class Contact:
    def __init__(self, name, phone):
        self.name = name
        self.phone = phone

class ContactManager:
    def __init__(self):
        self.contacts = []

    def add_contact(self, name, phone):
        contact = Contact(name, phone)
        self.contacts.append(contact)
        print(f"Contact '{name}' added successfully!")

    def view_contacts(self):
        if not self.contacts:
            print("No contacts found.")
        else:
            print("Contacts:")
            for index, contact in enumerate(self.contacts, start=1):
                print(f"{index}. {contact.name}: {contact.phone}")

    def delete_contact(self, index):
        if 1 <= index <= len(self.contacts):
            deleted_contact = self.contacts.pop(index - 1)
            print(f"Contact '{deleted_contact.name}' deleted.")
        else:
            print("Invalid contact index.")

def main():
    contact_manager = ContactManager()

    while True:
        print("\nContact Management Application")
        print("1. Add Contact")
        print("2. View Contacts")
        print("3. Delete Contact")
        print("4. Quit")
        choice = input("Enter your choice: ")

        if choice == '1':
            name = input("Enter contact name: ")
            phone = input("Enter contact phone: ")
            contact_manager.add_contact(name, phone)

        elif choice == '2':
            contact_manager.view_contacts()

        elif choice == '3':
            contact_manager.view_contacts()
            index = int(input("Enter the index of the contact to delete: "))
            contact_manager.delete_contact(index)

        elif choice == '4':
            print("Goodbye!")
            break

        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()
