How to merge two sorted linked list:

1. We need to create 3 variables and pass them as a parameter and one more variable to store the address of head initialize it with NULL
list1, list2, sort, newhead=null;
2. First sort variable will point to a node which has lesser value.

3. check if l1 is null then return l2;
4. check if l2 is null then return l1;
5 if they are not = null then check if l1 data is less than l2 if yes then sort will point to l1 else sort will point to l2.
6 initalize newhead varible with sort variable

7. Use a while loop and traverse till the end and check if the l1 value is less than l2 then sort will point to l1 else sort will point to l2

8.After while loop check if  l1 == null then sort will point to l2 else sort will point to l1


Source Code:
-----------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

Node* Merge(Node*l1, Node*l2, Node*sort){
    Node*new_head=NULL;
    
    if(l1==NULL)
    return l2;
    if(l2=NULL)
    return l1;
    if(l1 !=NULL && l2!= NULL){
        if(l1->data <=l2->data){
            sort=l1;
            l1=sort->next;
        }
        else{
            sort=l2;
            l2=sort->next;
        }
        new_head=sort;
    }

    while(l1 && l2){
        if(l1->data <=l2->data){
            sort->next=l1;
            sort=l1;
            l1=sort->next;
        }
        else{
            sort->next=l2;
            sort=l2;
            l2=sort->next;
        }
        
    }
    if(l1==NULL){
        sort->next=l2;
    }
    if(l2==NULL){
        sort-next=l1;
    }
}
int main(){
    
    
    
    
    return 0;
}