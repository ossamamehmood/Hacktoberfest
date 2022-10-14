#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * head=NULL;

void insert(int x){
    struct node *newnode=head;
    newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }    
}
void display(){
    struct node *current=head;
    printf("\n");
    while (current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    
}
void reverse(){
    struct node *current=head;
    struct node *prev=NULL;
    struct node *temp=NULL;
    while (current!=NULL)
    {    
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;

    }
    head=prev;
    
}


void main(){

    int a[5]={1,2,3,4,5};
    for (int i = 4; i>=0; i--)
    {
        insert(a[i]);
        
    }
    printf("linkedList");
    display();
    reverse();
    printf("reversedLinkedList");
    display();

}