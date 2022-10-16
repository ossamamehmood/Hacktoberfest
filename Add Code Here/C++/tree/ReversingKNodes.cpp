#include <iostream>
using namespace std;
//recursive method

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(node* &head, int val){
    node* n= new node(val);
     if(head==NULL){
         head=n;
         return;
     }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseK(node* &head, int k) {

    node* prevptr=NULL;
    node* currptr=head;
    node* nxtptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nxtptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nxtptr;
        count++;
        
    }

    if(nxtptr!=NULL){
    head->next=reverseK(nxtptr,k);
    }

    return prevptr;
}
int main()
{  
  node* head=NULL;
  insertAtTail(head,1);
    insertAtTail(head,2);
      insertAtTail(head,3);
      insertAtTail(head,4);
      insertAtTail(head,5);
      display(head);
      int k=2;
            node* newhead=reverseK(head,2);
      display(newhead);
      return 0;
}
