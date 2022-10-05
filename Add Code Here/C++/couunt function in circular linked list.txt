Write a count function in Circular Linkedlist

int count(Node* p)
int count=0;
do{

count++;
p=p->next;
}while(p!=head);

reutrn count;
}