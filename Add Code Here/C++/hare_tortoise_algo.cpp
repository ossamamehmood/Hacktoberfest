/*
Author : Rounak Ghosh
GitHub : rounak-ghosh
Institution : GCETTB
Date : 08/10/2022
*/

#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while (n != NULL) 
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void insertAtEnd(Node* &head, int val)
{
    Node* n = new Node();
    n -> data = val;
    if(head == NULL)
    {
        head = n;
        return;
    }    
    Node* last = head;
    while(last -> next != NULL)
        last = last->next;
    last -> next = n;
}

void makeCycle(Node* &head, int pos)        // making an cyclic linked list at pos
{
    Node* start = head;
    Node* temp = head;

    int count=1;
    while(temp->next!=NULL)
    {
        if(count == pos)
            start = temp;
        temp = temp->next;
        count++;
    }
    temp->next = start;
}

bool detectCycle(Node* &head)
{
    Node* slow = head;  // tortoise
    Node* fast = head;  // hare

    while(fast!=NULL && fast->next!=NULL)   // Acyclic linked list
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow)
            return true;
    }
}

void removeCycle(Node* &head)
{
    Node* slow =  head;
    Node* fast = head;

    do              // Using do while cuz we already know that it's a cyclic linked list
    {
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL; 
}

int main()          // Floyd's Algo     or      Hare & Tortoise Algo
{
    Node* head = new Node();

    head -> data = 10;
    head -> next = NULL;
 
    for(int i=20; i<100; i+=10)
        insertAtEnd(head, i);       // Regular Linked List

    makeCycle(head, 4);     // Cyclic Linked List

    if(detectCycle(head))
        cout << "Cyclic Linked List" << endl;
    else
        cout << "Acyclic Linked List" << endl;

    removeCycle(head);      // Acyclic Linked List - back to original

    if(detectCycle(head))
        cout << "Cyclic Linked List" << endl;
    else
        cout << "Acyclic Linked List" << endl;

    return 0;
}