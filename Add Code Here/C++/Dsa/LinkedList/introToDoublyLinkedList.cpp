#include <iostream>
using namespace std;



class Node {

  public:
  int data ;
  Node*prev;
  Node*next ;

  Node(int value){
    this->data= value;
    prev=NULL;
    next-NULL;  
  }
};


// printing the linked List 
void printDoublyLL(Node* head)
{
  Node* temp= head;

  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp= temp->next;
  }
  cout<<endl;

}

// Insertion At Head

void insertAthead(Node*&head, Node*&tail , int value)
{
  // If List is empty

  if(head==NULL)
  {
    Node * nodeToInsert = new Node(value);
    head= nodeToInsert;
    tail= nodeToInsert;
  }
  // List is not empty
  else{
    Node * nodeToInsert = new Node(value); // Step1-> Creating New node
    nodeToInsert->next = head; // linking the node at start
    head->prev= nodeToInsert;
    head= nodeToInsert; // updating the head
  }
}

// Insertion at Tail 
void insertAtTail(Node*&head, Node* &tail, int value)
{
  // If List is empty

  if(tail==NULL)
  {
    Node * nodeToInsert = new Node(value);
    head= nodeToInsert;
    tail= nodeToInsert;
  }
  // List is not empty
  else{
    Node * nodeToInsert = new Node(value); // Step1-> Creating New node
    nodeToInsert->prev = tail; // linking the node at start
    tail->next = nodeToInsert;
    tail= nodeToInsert; // updating the head
  }
}

int getLength(Node*head)
{
  int length=1;
  Node*temp= head;
  if(head==NULL)
  {
    return 0;
  }

  while( temp!=NULL)
  {
    length++;
    temp =temp->next;
  }
  return length;
}

Node* insertionAtPosition(Node* &head, Node* &tail , int value, int position)
{
  int length = getLength(head);

  if(position == 1)
  {
    insertAthead(head, tail , value);
  }
  else if(position >= length)
  {
    insertAtTail(head, tail, value);
  }
  else
  {
    int count = 1;
    Node *temp = head;
    while(count < position - 1)// position -1 because we want to stop just before the position we want to insert 
    {
      temp = temp->next;
      count++;
    }

    Node* nodeToInsert = new Node(value);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;

    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
  }

  return head; // Return the head of the modified list
}


int main() {

  // Node* temp = new Node(10);
  Node* head= NULL;
  Node* tail= NULL;

  insertAthead(head,tail,10);
  insertAthead(head,tail,20);
  insertAthead(head,tail,30);
  printDoublyLL(head);

  insertAtTail(head, tail, 100);
  insertAtTail(head, tail, 110);
  insertAtTail(head, tail, 120);
  printDoublyLL(head);

  
  insertionAtPosition(head,tail,40,4);
  insertionAtPosition(head,tail,130,8);
  printDoublyLL(head);


  return 0;
}