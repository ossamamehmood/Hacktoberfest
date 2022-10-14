
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
     SinglyLinkedListNode*temp=llist;
     int cnt=0;
      SinglyLinkedListNode*node1=new  SinglyLinkedListNode(data);
    if(position==1){
        node1->next=llist;
        llist=node1;
    }
    else{
       while(cnt<position-1) {
           cnt++;
           temp=temp->next;
       }
       node1->next=temp->next;
       temp->next=node1;
       }

   return llist;
}
