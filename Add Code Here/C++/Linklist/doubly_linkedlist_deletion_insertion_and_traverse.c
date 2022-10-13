#include<stdio.h>
#include<stdlib.h>
 struct node{
        int data;
        struct node *prev;
        struct node *next;
    };
struct node *head=NULL,*tail,*last;
void display(struct node *head){
    printf("NULL<->");
    while(head!=NULL){
        printf("%d<->",head->data);
        head=head->next;
    }
    printf("NULL");
}
void deleteend(){
    last=tail;
    tail=last->prev;
    last->prev->next=NULL;
    last->prev=NULL;
    free(last);
}
void addend(int info){
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=info;
     temp->next=NULL;
     temp->prev=NULL;
     if(head==NULL){
        head=temp;
        tail=temp;
     }
     else{
        tail->next=temp;
        temp->prev=tail;
        temp->next=NULL;
        tail=temp;
     }
    }
int main(){
    addend(1);
    addend(2);
    addend(3);
    addend(4);
    deleteend();
    display(head);
}