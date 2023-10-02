/*
C++ Program to demonstrate uses of new and delete operators and nested functions within a single class and various constructors
Created a class called "BookManager" that represents a single book management system with functionalities such as :
dynamic memory, adding book to collection, issue book, return book, displaying details of book as it is as wel as uppercase using toupper for char in every string 
and printing all details at every point 
*/
#include <iostream>         // Used for standard input/output stream (e.g., cout, cin)
#include <cstring>          // Used for various string manipulation functions
#include <cctype> // for toupper

using namespace std; //the using directive means to include the whole code written in the namespace in the closing scope.

class BookManager {
public://keeping everything public for easy understanding 
    class Book {//making a book record
    public:
        string title;
        string author;
        string isbn;//International Standard Book Number
        int totalCopies;//total copies of book available
        int issuedCopies;//issued copies not available 
        string location;//location of book

         // Default Constructor for book
            Book() : totalCopies(0), issuedCopies(0), location("") {}

            // One Argument Constructor for book
            Book(const string &isbn) : isbn(isbn), totalCopies(0), issuedCopies(0), location("") {}

            // Three Argument Constructor for book
            Book(const string &title, const string &author, const string &isbn)
                : title(title), author(author), isbn(isbn), totalCopies(0), issuedCopies(0), location("") {}
            // all arguments together for book
            Book(const string &title, const string &author, const string &isbn, int totalCopies, int issuedCopies, const string &location)
                : title(title), author(author), isbn(isbn), totalCopies(totalCopies), issuedCopies(issuedCopies), location(location) {
    
}
    };

    int numOfBooks;
    Book *books;  //dynamic array 

    BookManager() : numOfBooks(0), books(nullptr) {}//constructor for bookmanager //by default 0 books and the array will be empty thus pointing to NULL

    // Function declarations
    // Function declarations
    void searchBook(const string &searchStr); // Declare a function to search for a book by a search string.
    void issueBook(const string &isbn); // Declare a function to issue a book by its ISBN.
    void returnBook(const string &isbn); // Declare a function to return a book by its ISBN.
    void printBookDetails(const string &isbn); // Declare a function to print details of a book by its ISBN.

    // Define a function to print book details in uppercase.
    void printUpperCase(const string &isbn) {
        for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
            if (books[i].isbn == isbn) { // Check if the ISBN of the current book matches the provided ISBN.
                cout << "Title: " << convertToUpperCase_varun(books[i].title) << "\n"; // Print the book title in uppercase.
                cout << "Author: " << convertToUpperCase_varun(books[i].author) << "\n"; // Print the author's name in uppercase.
                cout << "ISBN: " << convertToUpperCase_varun(books[i].isbn) << "\n"; // Print the ISBN in uppercase.
                cout << "Total Copies: " << books[i].totalCopies << "\n"; // Print the total number of copies.
                cout << "Issued Copies: " << books[i].issuedCopies << "\n"; // Print the number of issued copies.
                cout << "Location: " << convertToUpperCase_varun(books[i].location) << "\n"; // Print the location in uppercase.
                return; // Exit the function after printing the book details.
            }
        }
        cout << "Book with ISBN " << isbn << " not found.\n"; // If the book is not found, print an error message.
    }

    // Helper function to convert a string to uppercase
    string convertToUpperCase_varun(const string &str) {
        string result;
        for (char c : str) { // Loop through each character in the input string.
            result += toupper(c); // Convert the character to uppercase and add it to the result string.
        }
        return result; // Return the resulting uppercase string.
    }

    // Declare a function to add a book to the collection.
    void addBook(const string &title, const string &author, const string &isbn, int totalCopies, const string &location);

    // Declare a function to locate a book by its ISBN.
    void locationBook(const string &isbn);


    ~BookManager() {//destructor
        delete[] books;  // Deallocate memory when the program exits
    }
};

// Function definitions using scope resolution operator
void BookManager::searchBook(const string &searchStr) {
    cout << "Search Results:\n"; // Print a header for search results.
    for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
        if (books[i].title.find(searchStr) != string::npos || books[i].author.find(searchStr) != string::npos) {
            // Check if the search string is found in the book's title or author.
            cout << "------------------------------------------------------------\n"; // Print a separator.
            cout << "Title: " << books[i].title << "\n"; // Print the book's title.
            cout << "Author: " << books[i].author << "\n"; // Print the book's author.
            cout << "ISBN: " << books[i].isbn << "\n"; // Print the book's ISBN.
            cout << "Total Copies: " << books[i].totalCopies << "\n"; // Print the total number of copies.
            cout << "Issued Copies: " << books[i].issuedCopies << "\n"; // Print the number of issued copies.
            cout << "Location: " << books[i].location << "\n"; // Print the book's location.
            cout << "Copies Available: " << (books[i].totalCopies - books[i].issuedCopies) << "\n";
            // Calculate and print the number of copies available that can be issued
        }
    }
    cout << "------------------------------------------------------------\n"; // Print a separator.
}

void BookManager::issueBook(const string &isbn) {
    for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
        if (books[i].isbn == isbn) { // Check if the book's ISBN matches the provided ISBN.
            if (books[i].totalCopies > 0) { // Check if there are available copies of the book.
                books[i].totalCopies--; // Decrement the total copies count.
                books[i].issuedCopies++; // Increment the issued copies count.
                cout << "Book " << books[i].title << " issued successfully.\n"; // Print a success message.
            } else {
                cout << "No copies available for " << books[i].title << ".\n"; // Print a message if no copies are available.
            }
            return; // Exit the function.
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n"; // Print an error message if the book is not found.
}


void BookManager::returnBook(const string &isbn) {
    for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
        if (books[i].isbn == isbn) { // Check if the book's ISBN matches the provided ISBN.
            if (books[i].issuedCopies > 0) { // Check if there are issued copies of the book.
                books[i].totalCopies++; // Increment the total copies count.
                books[i].issuedCopies--; // Decrement the issued copies count.
                cout << "Book " << books[i].title << " returned successfully.\n"; // Print a success message.
            } else {
                cout << "No copies issued for " << books[i].title << ".\n"; // Print a message if no copies are issued.
            }
            return; // Exit the function.
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n"; // Print an error message if the book is not found.
}

void BookManager::printBookDetails(const string &isbn) {
    for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
        if (books[i].isbn == isbn) { // Check if the book's ISBN matches the provided ISBN.
            cout << "Title: " << books[i].title << "\n"; // Print the book's title.
            cout << "Author: " << books[i].author << "\n"; // Print the book's author.
            cout << "ISBN: " << books[i].isbn << "\n"; // Print the book's ISBN.
            cout << "Total Copies: " << books[i].totalCopies << "\n"; // Print the total number of copies.
            cout << "Issued Copies: " << books[i].issuedCopies << "\n"; // Print the number of issued copies.
            cout << "Location: " << books[i].location << "\n"; // Print the book's location.
            return; // Exit the function.
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n"; // Print an error message if the book is not found.
}



void BookManager::addBook(const string &title, const string &author, const string &isbn, int totalCopies, const string &location) {
    for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
        if (books[i].isbn == isbn) { // Check if the book's ISBN matches the provided ISBN.
            books[i].totalCopies += totalCopies; // Increment the total copies count for an existing book.
            cout << "Added " << totalCopies << " copies of " << books[i].title << ".\n"; // Print a success message.
            return; // Exit the function.
        }
    }

    // If the book with the provided ISBN doesn't exist, create a new book and add it to the array.
    Book *newBooks = new Book[numOfBooks + 1]; // Create a new array to hold books with increased size.
    for (int i = 0; i < numOfBooks; ++i) {
        newBooks[i] = books[i]; // Copy existing books to the new array.
    }
    newBooks[numOfBooks] = Book(title, author, isbn, totalCopies, 0, location); // Create a new Book object and add it to the new array.

    delete[] books; // Deallocate memory for the old books array.
    books = newBooks; // Update the books pointer to point to the new array.
    numOfBooks++; // Increment the total number of books.
    
    cout << "Book " << title << " added successfully.\n"; // Print a success message.
}

void BookManager::locationBook(const string &isbn) {
    for (int i = 0; i < numOfBooks; ++i) { // Loop through the list of books.
        if (books[i].isbn == isbn) { // Check if the book's ISBN matches the provided ISBN.
            cout << "Location of " << books[i].title << ": " << books[i].location << "\n"; // Print the book's location.
            return; // Exit the function.
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n"; // Print an error message if the book is not found.
}


int main() {
    BookManager Manager;

    int choice;
    string searchStr, isbn;
    string title, author, location;
    int totalCopies;

    // Start an infinite loop to display the menu and handle user input.
    while (true) {
        cout << "Menu: \n";
        cout << "1. Search Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Print Book Details\n";
        cout << "5. Print Book Details in Uppercase\n";
        cout << "6. Add Book\n";
        cout << "7. Location of Book\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read the user's choice.

        switch (choice) {
            case 1:
                cout << "Enter search string: ";
                cin >> searchStr;
                Manager.searchBook(searchStr); // Call the searchBook function with the user's input.
                break;

            case 2:
                cout << "Enter ISBN to issue: ";
                cin >> isbn;
                Manager.issueBook(isbn); // Call the issueBook function with the user's input.
                break;

            case 3:
                cout << "Enter ISBN to return: ";
                cin >> isbn;
                Manager.returnBook(isbn); // Call the returnBook function with the user's input.
                break;

            case 4:
                cout << "Enter ISBN to print details: ";
                cin >> isbn;
                Manager.printBookDetails(isbn); // Call the printBookDetails function with the user's input.
                break;

            case 5:
                cout << "Enter ISBN to print details in uppercase: ";
                cin >> isbn;
                Manager.printUpperCase(isbn); // Call the printUpperCase function with the user's input.
                break;

            case 6:
                cout << "Enter book details (title author isbn total_copies location): ";
                cin >> title >> author >> isbn >> totalCopies >> location;
                Manager.addBook(title, author, isbn, totalCopies, location); // Call the addBook function with the user's input.
                break;

            case 7:
                cout << "Enter ISBN to get location: ";
                cin >> isbn;
                Manager.locationBook(isbn); // Call the locationBook function with the user's input.
                break;

            case 8:
                cout << "Exiting Program...\n";
                return 0; // Exit the program.

            default:
                cout << "Enter a Valid Option: \n"; // Display a message for an invalid menu choice.
                break;
        }
    }

    return 0;
}