#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;
    
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node *head;
    
    LinkedList()
    {
        head =NULL;
    }
    
    void addNode(int data)
    {
        Node *temp = new Node(data);
        if(head == NULL)
            head = temp;
        else
        {
            Node *x = head;
            
            while(x->next != NULL)
                x = x->next;
            
            x->next = temp;
            temp->next = NULL;
        }
    }
    
    void reverseLinkedList() 
    {
        Node *prevNode = NULL;
        Node *currentNode = NULL;
        Node *nextNode = NULL;
    
        currentNode = head;
    
        while(currentNode != NULL)
        {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
    
        head = prevNode;
    }
    
    void printLL()
    {
        Node *temp = head;
        
        while(temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};



int main() {
   LinkedList l;
   int n;
   cout << "Enter the number of elements in linked list: " << endl;
   cin >> n;
   
   for(int i=0; i<n; i++)
   {
       int x;
       cout << "Enter element no. " << i << " : ";
       cin >> x;
       l.addNode(x);
   }
   
   cout << "Given Linked List" << endl;
   l.printLL();
   l.reverseLinkedList();
   cout << "Reversed Linked List" << endl;
   l.printLL();

    return 0;
}