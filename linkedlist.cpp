#include<iostream>
using namespace std;
class node{
        public:
        int data;
        node* next;
        node(int d){
        data=d;
        next=NULL;
        
    }
};
void InsertatFront(node* &head,node* &tail,int d){
    node *n=new node(d);
    if(head==NULL){
        head=tail=n;
    }
    else{
          n->next=head;
          head=n;

    }


}
void printLL(node *head){
    while(head!=NULL){
        cout<<head->data<<">>";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
    
int main(){
    node* head;
    node* tail;
    head=tail=NULL;
    InsertatFront(head,tail,1);
    InsertatFront(head,tail,2);
    InsertatFront(head,tail,3);
    InsertatFront(head,tail,4);
    InsertatFront(head,tail,5);
    printLL(head);


}