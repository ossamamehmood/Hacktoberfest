1. find the middle
2. point middle to head
3 traverse another part
5 point the last to the first one 

Void splitList(Node*head, Node*head1, Node*head2){
    Node*slow = head;
    Node*fast=head;
    
    while(head!=fast && fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    head1=head;
    head2=slow->next;
    
    slow->next=head1;
    Node*current= head2;
    while(current!=head){
        current=current->next;
    }
    current->next=head;
}