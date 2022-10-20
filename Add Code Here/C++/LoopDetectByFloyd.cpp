#include<bits/stdc++.h>
using namespace std;
 
class Node { 
public: 
    int data; 
    Node* next; 
}; 

void push(Node** head_ref, int data) { 
    Node* node = new Node(); 
    node->data = data; 
    node->next = (*head_ref); 
    (*head_ref) = node; 
} 

bool detectLoop(Node* head){
    Node* slow =head;
    Node* fast =head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return true;
    }
    return false;
}

int main() { 
	
    Node* head = NULL; 
    push(&head, 2); 
    push(&head, 20); 
    push(&head, 40); 
    push(&head, 50); 
    push(&head, 75);
    // Added sample loop
    head->next->next->next = head; 
    if (detectLoop(head)) 
        cout << "Loop is Found"; 
    else
        cout << "No Loop is Found"; 
    return 0; 
} 