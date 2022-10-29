#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *n1){
    struct Node *ptr = n1;
   do
   {
       printf("Element is %d \n" , ptr-> data);
       ptr = ptr->next;
   }
   while(ptr-> ! =NULL);
}

struct Node * insertAtFirst(struct Node *n1, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = n1->next;
    while(p->next != n1){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = n1;
    n1 = ptr;
    return n1;

}

int main(){
    
    struct Node *n1;
    struct Node *n2;
    struct Node *n3;
    struct Node *n4;

    // Allocate memory for nodes in the linked list in Heap
    n1 = (struct Node *)malloc(sizeof(struct Node));
    n2 = (struct Node *)malloc(sizeof(struct Node));
    n3 = (struct Node *)malloc(sizeof(struct Node));
    n4 = (struct Node *)malloc(sizeof(struct Node));

    // Link first and n2 nodes
    n1->data = 4;
    n1->next = n2;
    n1->prev = NULL ;

    // Link n2 and n3 nodes
    n2->data = 3;
    n2->next = n3;
    n2->prev = n1;

    // Link n3 and n4 nodes
    n3->data = 6;
    n3->next = n4;
    n3->prev = n2;

    // Terminate the list at the n4 node
    n4->data = 1;
    n4->next = NULL ;
    n4->prev = n3;

    printf("Doubly Linked list before insertion\n");
    linkedListTraversal(n1);
    // n1 = insertAtFirst(n1, 54);
    // n1 = insertAtFirst(n1, 58);
    // n1 = insertAtFirst(n1, 59);
    // printf("Circular Linked list after insertion\n");
    // linkedListTraversal(n1);
    return 0;
}