#include <stdio.h>
#include <stdlib.h>

struct Node{   //Creating a node // node comprises head and next(address of next head)
    int data;
    struct Node *next;
}*head;

// Inserting element at the beginning
void insert_begin(int x){
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node*));
    new_node -> data = x;
    if(head == NULL){
        head = new_node;
        new_node -> next = NULL;
    }
    else{
        new_node -> next = head;
        head = new_node;
    }
}

void print_list(struct Node *n){   // to display the contents of linked list
    while (n != NULL){
        printf("%d  ",n->data);
        n = n->next;
    }
}

int main(){
    //struct Node *head = NULL;  // Since we're inserting at front, hence cannot assign HEAD as NULL.
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));


    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = NULL;

    insert_begin(50);

    //print_list(head);

    //insert_begin(5);

    print_list(head);

    return 0;
}