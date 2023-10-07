#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete a node with given value from the linked list
    void remove(int value) {
        if (head == nullptr) {
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome() {
        Node* slow = head;
        stack<int> s;

        // Push elements from the first half of the linked list onto the stack
        while (slow != nullptr) {
            s.push(slow->data);
            slow = slow->next;
        }

        // Compare elements from the second half of the linked list with the stack
        slow = head;
        while (slow != nullptr) {
            int top = s.top();
            s.pop();
            if (slow->data != top) {
                return false;
            }
            slow = slow->next;
        }
        return true;
    }

    // Function to find the middle node of the linked list
    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function for testing the LinkedList class
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Original Linked List: ";
    list.display();

    cout << "Middle Node: " << list.findMiddle() << endl;

    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    list.reverse();
    cout << "Reversed Linked List: ";
    list.display();

    list.remove(3);
    cout << "Linked List after removing 3: ";
    list.display();

    return 0;
}
