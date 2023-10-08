#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //destructor

};

void insertAtHead(Node* &head, int d){  
    //new node create
    Node* temp = new Node(d);
    //null pointer hatao aur head ko point karao
    temp->next = head; 
    head = temp;

}

void insertAtTail(Node* &tail, int d){
    //create new node
    Node* temp = new Node(d);
    //tail ko temp pe point karwao 
    //aur tail point karega null pe
    tail->next = temp;
    tail = temp;

}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    Node* temp = head;
    int count = 1;
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    
    while(count<position-1 && temp->next!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    //creatng a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}



void traverseLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        //print data at the current node 
        cout << temp->data <<" ";
        //check address for the next node
        temp = temp->next;
    }
    cout<<endl;
}



void deleteNode(int pos, Node* &head, Node* &tail){
    
    if(pos == 1){   
        Node* temp = head ;
        head = head -> next;
        delete temp;
        return ;

    }
    //deleting any middle or last mode
    else{
        int count = 1;
        Node* curr = head;
        Node* prev = NULL;

        
        while(count < pos){
            prev = curr ;
            curr = prev->next;
            count ++;
            if(curr -> next == NULL){
                tail = prev;
            }
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main(){
    Node* n0 = new Node(1);

    //Node* n1 = new Node(10);
    //n0->next = n1;

    //Node* n2 = new Node(15);
    //n1->next = n2;
    //cout<<endl;
    //traverseLL(n0);
    //cout<< n0->data<<endl;
    //cout<< n0->next<<endl;
    
    Node* head = n0;
    insertAtHead(head,2); // inserting in the first element of the LL
    traverseLL(head);

    //Node* tail = n2;
    //insertAtTail(tail,30); // inserting  30 in the back of the LL
    //traverseLL(head);

    //insertAtPosition(head, tail, 3, 22); // inserting  3 in the position of the LL
    //traverseLL(head);
    insertAtHead(head,3); 
    traverseLL(head);
    
    insertAtHead(head,4); 
    traverseLL(head);
    
    insertAtHead(head,5); 
    traverseLL(head);

    Node* tail = new Node(0);
    n0->next = tail;

    deleteNode(6,head,tail);
    traverseLL(head);

    cout<< "head: "<<head->data<<"\n";
    cout<< "tail: "<<tail->data<<"\n";

    //delete n0,n1,n2,*head;

    
    
    
}