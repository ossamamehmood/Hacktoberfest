SinglyLinkedListNode*insertNodeAtTail( SinglyLinkedListNode* head,int data){
     SinglyLinkedListNode*temp=head;
      SinglyLinkedListNode*node1=new  SinglyLinkedListNode(data);
     if(head==0){
         head=node1;
     }
     else{
         while(temp->next!=NULL){
             temp=temp->next;
         }
         temp->next=node1;

     }
     return head;
 }
