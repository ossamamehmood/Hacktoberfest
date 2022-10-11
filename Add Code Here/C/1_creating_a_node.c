#include<stdio.h>
#include<stdlib.h>


//creation of a node in a single linked list


struct node{      //initializing (structuring) a node
    int data;         //data part of the node
    struct node *link;       //link part of the node where to connects to a different node
};

int main(){
    
    struct node *head = NULL;                       //declare a separate node/pointer to point it to the main node (so as to have easy access in the linked list)
    head=(struct node *)malloc(sizeof(struct node));     //assigning the memory location of the main node to the head node so that it points to the main node

    head->data = 45;                    //head pointing to data.........data is now 45
    head->link = NULL;                  //head pointing to link.........link is now NULL since there are no other nodes to point to

    printf("%d",head->data);
    return 0;
}