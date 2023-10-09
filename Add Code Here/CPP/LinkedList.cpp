#include <iostream>
using namespace std;

class LinkedList {
private:
    class Node {
    public:
        string data;
        Node* next;

        Node(string data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void printlist() {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->data << " -> ";
            currNode = currNode->next;
        }
        cout << "null" << endl;
    }

    void addfirst(string data) {
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        size++;
    }

    void addlast(string data) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = newnode;
        } else {
            Node* lastnode = head;
            while (lastnode->next != nullptr) {
                lastnode = lastnode->next;
            }
            lastnode->next = newnode;
        }
        size++;
    }

    void deletefirst() {
        if (head == nullptr) {
            cout << "List is already Empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deletelast() {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* currNode = head;
            while (currNode->next->next != nullptr) {
                currNode = currNode->next;
            }
            delete currNode->next;
            currNode->next = nullptr;
        }
        size--;
    }

    int getSize() {
        return size;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.addfirst("Dev");
    list.addfirst("Datir");
    list.printlist();
    list.addlast("From");
    list.addlast("Amravati");
    list.deletefirst();
    list.deletelast();
    list.deletelast();
    list.addlast("Datir");
    list.printlist();
    cout << "Size: " << list.getSize() << endl;

    return 0;
}
