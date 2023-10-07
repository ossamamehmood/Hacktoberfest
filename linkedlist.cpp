#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int val) : value(val), next(nullptr) {}
        Node(int val, Node* nxt) : value(val), next(nxt) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << "END" << std::endl;
    }

    void insert(int value, int index) {
    if (index < 0 || index > size) {
        std::cerr << "Invalid index for insertion" << std::endl;
        return;
    }

    Node* newNode = new Node(value);

    if (index == 0) {
        // Insert at the beginning
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    } else if (index == size) {
        // Insert at the end
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    } else {
        // Insert at a specific index
        Node* prev = nullptr;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
    }

    size++;
}

    void insertFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void insertLast(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int deleteFirst() {
        if (head == nullptr) {
            std::cerr << "The list is empty. Cannot delete from an empty list." << std::endl;
            return -1; // Return a default value or handle the error as needed.
        }

        int deletedValue = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }

        size--;

        return deletedValue;
    }

    int deleteLast() {
        if (head == nullptr) {
            std::cerr << "The list is empty. Cannot delete from an empty list." << std::endl;
            return -1; // Return a default value or handle the error as needed.
        }

        int deletedValue;
        if (head == tail) {
            // If there's only one element in the list
            deletedValue = head->value;
            delete head;
            head = tail = nullptr;
        } else {
            // Find the second-to-last node
            Node* secondLast = head;
            while (secondLast->next != tail) {
                secondLast = secondLast->next;
            }

            deletedValue = tail->value;
            delete tail;
            tail = secondLast;
            tail->next = nullptr;
        }

        size--;

        return deletedValue;
    }

    int deleteNode(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Invalid index for deletion" << std::endl;
            return -1; // Return a default value or handle the error as needed.
        }

        int deletedValue;

        if (index == 0) {
            // Deleting the first node
            deletedValue = head->value;
            Node* temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            // Deleting a node other than the first one
            Node* prev = nullptr;
            Node* current = head;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }

            deletedValue = current->value;
            prev->next = current->next;

            if (current == tail) {
                tail = prev;
            }

            delete current;
        }

        size--;

        return deletedValue;
    }

    void reverse() {
        if (size < 2) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = current->next;

        while (current != nullptr) {
            current->next = prev;
            prev = current;
            current = nextNode;
            if (nextNode != nullptr) {
                nextNode = nextNode->next;
            }
        }

        head = prev;
    }

    Node* findMiddle() {
        if (head == nullptr) {
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    int getMiddleValue() {
        Node* middle = findMiddle();
        if (middle != nullptr) {
            return middle->value;
        } else {
            cerr << "The list is empty." << endl;
            return -1; // Return a default value or handle the error as needed.
        }
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome() {
        if (head == nullptr) {
            return true; // An empty list is considered a palindrome
        }

        Node* middle = findMiddle();

        // Reverse the second half of the list
        Node* prev = nullptr;
        Node* current = middle;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        // Compare the first and reversed second halves
        Node* left = head;
        Node* right = prev;

        while (left != nullptr && right != nullptr) {
            if (left->value != right->value) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        // Restore the original list
        current = prev;
        prev = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return true;
    }



};

int main() {
    LinkedList myList; // Create an instance of the LinkedList

    // Insert elements into the list
    myList.insertLast(1);
    myList.insertLast(2);
    myList.insertLast(3);
    myList.insertLast(4);

    // Display the initial list
    myList.display(); // Output: 1 -> 2 -> 3 -> 4 -> END

    //Display middle value of linked list    
     int middleValue = myList.getMiddleValue();
    if (middleValue != -1) {
        cout << "Middle element: " << middleValue << endl;
    }


    // Delete elements from the list
    myList.deleteFirst();
    myList.deleteLast();

    // Display the modified list
    myList.display(); // Output: 2 -> 3 -> END

    // Insert an element at a specific index
    myList.insert(5, 1);

    // Display the modified list
    myList.display(); // Output: 2 -> 5 -> 3 -> END

    // Delete an element at a specific index
    myList.deleteNode(1);

    // Display the modified list
    myList.display(); // Output: 2 -> 3 -> END

    // Reverse the list
    myList.reverse();

    // Display the reversed list
    myList.display();

    // Check if the list is a palindrome
    if (myList.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }


    return 0;
}
