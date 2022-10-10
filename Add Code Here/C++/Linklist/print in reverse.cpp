SinglyLinkedListNode* reversePrint(SinglyLinkedListNode* llist) {
        if(llist==NULL || llist->next==NULL){
        return llist;
    }
SinglyLinkedListNode* curr=llist;
SinglyLinkedListNode* prev=NULL;
SinglyLinkedListNode* forward=NULL;

while(curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;


}
return prev;
}
