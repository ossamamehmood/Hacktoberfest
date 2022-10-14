Singly Linked list Reversing Recursive Approach

Node* Reverse(Node* head){

if(head==null || head->next ==null){
return head;

}

Node* newhead= reverse(head->next);
Node current= head->next;
current->next = head;
head->next = null;

return newhead;
}