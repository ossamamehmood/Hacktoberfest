class Library:
    def __init__(self):
        self.books = {}

    def add_book(self, title, author, ISBN):
        if ISBN not in self.books:
            self.books[ISBN] = {'title': title, 'author': author, 'available': True}
            print(f"{title} by {author} (ISBN: {ISBN}) has been added to the library.")
        else:
            print("Book with the same ISBN already exists in the library.")

    def view_books(self):
        if not self.books:
            print("No books available in the library.")
        else:
            print("Books available in the library:")
            for ISBN, book in self.books.items():
                availability = "Available" if book['available'] else "Not Available"
                print(f"{book['title']} by {book['author']} (ISBN: {ISBN}) - {availability}")

    def issue_book(self, ISBN):
        if ISBN in self.books:
            if self.books[ISBN]['available']:
                self.books[ISBN]['available'] = False
                print(f"{self.books[ISBN]['title']} has been issued.")
            else:
                print(f"{self.books[ISBN]['title']} is already issued.")
        else:
            print("Book not found in the library.")

    def return_book(self, ISBN):
        if ISBN in self.books:
            if not self.books[ISBN]['available']:
                self.books[ISBN]['available'] = True
                print(f"{self.books[ISBN]['title']} has been returned.")
            else:
                print(f"{self.books[ISBN]['title']} is already available in the library.")
        else:
            print("Book not found in the library.")

    def delete_book(self, ISBN):
        if ISBN in self.books:
            del self.books[ISBN]
            print("Book has been deleted from the library.")
        else:
            print("Book not found in the library.")

def main():
    library = Library()

    while True:
        print("\nLibrary Management System Menu:")
        print("1. Add Book")
        print("2. View Books")
        print("3. Issue Book")
        print("4. Return Book")
        print("5. Delete Book")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            title = input("Enter the title of the book: ")
            author = input("Enter the author of the book: ")
            ISBN = input("Enter the ISBN of the book: ")
            library.add_book(title, author, ISBN)
        elif choice == '2':
            library.view_books()
        elif choice == '3':
            ISBN = input("Enter the ISBN of the book to issue: ")
            library.issue_book(ISBN)
        elif choice == '4':
            ISBN = input("Enter the ISBN of the book to return: ")
            library.return_book(ISBN)
        elif choice == '5':
            ISBN = input("Enter the ISBN of the book to delete: ")
            library.delete_book(ISBN)
        elif choice == '6':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
