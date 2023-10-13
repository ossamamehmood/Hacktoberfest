#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& name, const string& phoneNumber) {
        Contact newContact;
        newContact.name = name;
        newContact.phoneNumber = phoneNumber;
        contacts.push_back(newContact);
        cout << "Contact added: " << name << ", " << phoneNumber << endl;
    }

    void displayContacts() {
        cout << "Address Book:" << endl;
        for (const Contact& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << endl;
        }
    }
};

int main() {
    AddressBook addressBook;

    while (true) {
        cout << "Address Book Application" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter contact name: ";
                cin.ignore();
                string name;
                getline(cin, name);
                cout << "Enter phone number: ";
                string phoneNumber;
                cin >> phoneNumber;
                addressBook.addContact(name, phoneNumber);
                break;
            }
            case 2:
                addressBook.displayContacts();
                break;
            case 3:
                cout << "Exiting the Address Book Application. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
