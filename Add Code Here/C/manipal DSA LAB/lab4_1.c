#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* generator(int len)
{

    struct node *head,*temp;
    head=(struct node*)malloc(sizeof(struct node()));
    printf("Enter data");
    scanf("%d",&head->data);
    temp=head;
    while(len!=1)
    {
        temp->next=(struct node*)malloc(sizeof(struct node()));
        temp=temp->next;
        printf("Enter data");
        scanf("%d",&temp->data);
        len--;
    }
    return head;
}
int main()
{
    int len,pos;
    struct node *temp,*pred,*succ,*head;
    printf("Enter the length of the linked list");
    scanf("%d",&len);
    head=generator(len);
    //how to delete a node in between 
    printf("Enter node to delete");
    scanf("%d",&pos);
    temp=head;
    for(int i=1;i<pos;i++)
    {
        pred=temp;
        temp=temp->next;
        succ=temp->next;
    }
    pred->next=succ;
    free(temp);
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    return 0;
}

