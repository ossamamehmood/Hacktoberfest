#include <iostream>
// (Basically a 2 pointer approach)
// We define a Node struct to represent each node in the linked list. Each node contains an integer value (data) and a pointer to the next node (next).
// The detectLoop function uses the Floyd's Tortoise and Hare algorithm to detect a loop in the linked list. It initializes two pointers, slow and fast, both initially pointing to the head of the list. The fast pointer advances by two steps while the slow pointer advances by one step in each iteration of the while loop.
// If there is a loop in the linked list, the fast pointer will eventually catch up to the slow pointer, and we return true to indicate that a loop has been detected. If there is no loop, the fast pointer will reach the end of the list (i.e., become nullptr), and we return false.
// In the main function, we create a sample linked list with a loop for testing purposes.
// We call the detectLoop function to check for a loop in the linked list and print the result.
// Finally, we free the memory allocated for the nodes using delete to avoid memory leaks
// Definition of a Node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to detect a loop in a linked list
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow pointer by one step
        fast = fast->next->next;    // Move fast pointer by two steps

        if (slow == fast) {
            return true;  // Loop detected
        }
    }

    return false; // No loop detected
}

int main() {
    // Create a sample linked list with a loop
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;  // Creating a loop from fifth to second

    // Check for a loop in the linked list
    if (detectLoop(head)) {
        std::cout << "Loop detected in the linked list." << std::endl;
    } else {
        std::cout << "No loop detected in the linked list." << std::endl;
    }
    return 0;
}
