#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {

    public:

    int value;
    node* next; //pointer variable the next node.
};
int main()

//one two.... are pointer variable

{
    node* head;   //initialising of pointer with null
    node* one = NULL;
    node* two = NULL;  
    node* three = NULL; 
    node* four = NULL;  

    one = new node(); // request memory for variable
    two = new node();  //allocation of memory 
    three = new node();  
    four = new node();

    one->value =1; // assign values of the pointers
    two->value =2;
    three->value =3; 
    four->value =4;

    one->next = two;     //connecting nodes
    two->next = three;
    three->next = four;
    four->next =NULL;
    
    head = one;
    while (head != NULL)
    {
        cout<< head->value;
        head = head->next;     //printing values.....
     
    }
               
}
