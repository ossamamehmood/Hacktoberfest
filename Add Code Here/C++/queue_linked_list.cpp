#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// Implementation of a queue using a linked list

// Define a Node class for the elements of the linked list
template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    
public:
    Node(T value) {
        data = value;
        next = NULL;
    }
};

// Define a queue class using a linked list
template <typename T>
class que {
public:
    int len;
    Node<T>* head;
    Node<T>* tail;
    
    que() {
        len = 0;
        head = tail = NULL;
    }
   
    // Insert an element at the end of the queue
    void insert(T data) {
        len++;
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    };
   
    // Remove an element from the front of the queue
    void pop() {
        if (head == NULL) return;
        Node<T>* temp = head;
        head = head->next;
        delete(temp);
        len--;
    };
   
    // Peek at the front element of the queue
    int peek() {
        if (head == NULL) return -1;
        return head->data;
    };
};

int main() {
    // File input/output for testing purposes
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); // Open input.txt in reading mode
        freopen("output.txt", "w", stdout); // Open output.txt in writing mode
    #endif
        
    // Create a queue of integers
    que<int> q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(5);
    
    // Remove the first element from the queue
    q.pop();
     
    // Print the remaining elements in the queue
    while (q.len > 0) {
        cout << q.peek() << " ";
        q.pop();
    }
}
