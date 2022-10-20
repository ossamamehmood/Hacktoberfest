#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

Node *input(){
    int data;
    cout<<"Start entering the data for the LL "<<endl;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    char cont ='y';
    
    while(cont == 'y'){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;
        }
        
        cout<<"Do you wan to continue?(y/n) ";
        cin>>cont;
        if(cont=='y'){
            cin>>data;
        }
    }
    return head;
}

Node *interChange(Node *head, int n){

    int len = length(head);
    
    Node *newhead;
    Node *newtail;
    Node *temp = head;
    int count =1;
    
    while(temp->next != NULL){
        if(count==len-n){
            newtail=temp;
        }
        if(count==len-n+1){
            newhead=temp;
        }
        count++;
        temp=temp->next;
    }
    
    temp->next=head;
    newtail->next = NULL;
    
    return newhead;
}

int main()
{
   Node *head = input();
   print(head);
   
   cout<<endl<<endl;
   
   cout<<"Enter N :";
   int nn;
   cin>>nn;
   
   head = interChange(head,nn);
   print(head);
   
   return 0;
}
