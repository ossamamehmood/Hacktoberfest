#include<bits/stdc++.h>
using namespace std;
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 

//Pushing a Node to Linked List  
void push(Node** head_ref, int data) { 
    Node* node = new Node(); 
    node->data = data; 
    node->next = (*head_ref); 
    (*head_ref) = node; 
} 

//Detection of Loop using Floyd’s Cycle-Finding Algorithm
bool detectLoop(Node* head){
    Node* s=head;Node* f=head;
    while(s!=NULL && f!=NULL && f->next!=NULL) {
        s=s->next;
        f=f->next->next;
        if(f==s) return true;
    }
    return false;
}

int main() { 
	
    Node* head = NULL; 
    // push the desired nodes
    push(&head, 2); 
    push(&head, 20); 
    push(&head, 40); 
    push(&head, 50); 
    push(&head, 75);
  
    // Sample Loop
    head->next->next->next = head; 
    if (detectLoop(head)) 
        cout << "Loop is Found"; 
    else
        cout << "No Loop is Found"; 
    return 0; 
} 