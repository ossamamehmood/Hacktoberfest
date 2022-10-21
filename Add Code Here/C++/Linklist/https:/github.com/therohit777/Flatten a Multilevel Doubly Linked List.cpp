/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {
public:
    Node* flatten(Node* head) {
     Node * dummyHead = head;   
     stack <Node*> stack;   
     while(head || !stack.empty())
     {
       if(head && head -> child)
       { 
        if(head -> next) stack.push(head -> next);   
             
        head -> next = head -> child;  
        head -> next -> prev = head;   
        head -> child = nullptr;   
       }
       else if(!head -> next && !stack.empty())
       {                 
        head -> next= stack.top(); 
        head -> next -> prev = head; 
        stack.pop();
	   }
       if(head) head = head -> next;  
     }   
        return dummyHead;
    }
};
