#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void prepend(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void remove(int val) {
        if (!head) return;
        
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == val) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    
    myList.append(10);
    myList.append(20);
    myList.append(30);
    
    myList.display();
    
    myList.prepend(5);
    myList.prepend(15);
    
    myList.display();
    
    myList.remove(20);
    
    myList.display();
    
    return 0;
}
