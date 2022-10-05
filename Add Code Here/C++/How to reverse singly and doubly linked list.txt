Singly Linked list Reversed Function:
1. Iterative Way:
Node* reverse(Node*n){
Node* preptr=NULL;
Node* currentptr=head;
Node*nextptr;

while(currentptr!=NULL){
nextptr=currentptr->next;
currentptr->next=prevptr;
preptr=currentptr;
currentptr=nextptr;
}

2. Recursive Way:

Node recursive(Node* head)
{
Node*p, *q;

if(head==null)
return;

p=head;

q=p->next;

if(q==null)
return;
q=  recursive(q)
p->next->next=p;
p->next = null;
return q;
}

====================================================================================================
Doubly Linkedlist Reversed Function
Node*reverse(){
Node*current=head;
if(current==NULL)
cout<<"No Node Exist in the  linkedList"<<endl;
else if(current->next==null)
cout<<"There  is only one element in the linkedlist"<<endl;
else if{
while(current !=NULL)
Node*temp= current->prev;
current->prev=current->next;
current->next=temp;
current=current->previ;


}
else if (temp!=NuLL){
temp=temp->prev  // this the new head    


// Important Points:
1. temp points to previous node
2. the previous link of the current node will point to the next node
3. the next node will point to temp
4. go to next node
but the next node is pointed by previous node of the current node
}
