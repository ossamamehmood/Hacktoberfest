#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev= NULL;
    }

};
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

int getLength(Node* head){
    int len =  0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;

}

void Insertathead(Node* &head ,Node* &tail, int d){
    if(head == NULL ){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev= temp;
        head = temp;
    }
}

void InsertatTail(Node* &tail, Node* &head , int d){
    if(tail == NULL ){
        Node* temp = new Node(d);
        tail =temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev =  tail;
        tail = temp;
    }

}

void insertatmild(Node* &head , Node* &tail , int position , int d){
    if(position == 1) {
        Insertathead(head,tail,d);
    }else{
        Node* temp = head;
        Node* app = new Node(d);
        int cnt = 1;
        while(cnt < position-1){
            temp = temp->next;
            cnt++;
        }
        app->next = temp->next;
        temp->next->prev= app;
        temp->next =  app;
        app->prev =temp;
        if( temp->next == NULL){
            tail = app;
        }
    }
}
 

int main(){
    Node* tail = NULL;
    Node* head = NULL;
    // print(head);

    // Insertathead(head,34);
    // Insertathead(head,14);
    // Insertathead(head,54);
    // //print(head);
    // //cout << getLength(head) << endl;

    InsertatTail(tail,head,1);
    InsertatTail(tail,head,2);
    InsertatTail(tail,head,3);
    InsertatTail(tail,head,4);
    InsertatTail(tail,head,5);

    insertatmild(head,tail,3,56);
    //insertatmild(head,tail,7,554);

    print(head);


    return 0;
}