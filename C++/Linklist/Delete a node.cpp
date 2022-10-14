


SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
int cnt=0;
SinglyLinkedListNode* temp=llist;

while(cnt<position-1){
    temp=temp->next;
    cnt++;
}
if(position==0) {
    llist=temp->next;
}
temp->next=temp->next->next;

return llist;
}
