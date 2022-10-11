#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*start;
void traversal(struct node*p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->link;
    }
}
struct node*insertatstart(struct node*p)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted at beginning : ");
    scanf("%d",&temp->data);
    temp->link=p;
    p=temp;
    return p;
}
struct node*insertatend(struct node*p)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node)),*ptr;
    ptr=p;
    printf("\nEnter the data to be inserted at end : ");
    scanf("%d",&temp->data);
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    temp->link=NULL;
    return p;
}
struct node*insertinbetween(struct node*pt)
{
    int num;
    printf("\nEnter the element after which node be inserted : ");
    scanf("%d",&num);
    struct node*temp=(struct node*)malloc(sizeof(struct node)),*p,*ptr;
    printf("Enter the number for new node : ");
    scanf("%d",&temp->data);
    ptr=pt;
    while(ptr->data!=num)
    {
        ptr=ptr->link;
    }
    p=ptr->link;
    ptr->link=temp;
    temp->link=p;
    return pt;
    
    
}
struct node*deleteatstart(struct node*p)
{
    printf("\nLinked List after deletion of element in beginning \n");
    struct node*q;
    q=p;
    q=q->link;
    return q;
}
struct node*deleteatend(struct node*p)
{
    printf("\nLinked List after deletion of element in end \n");
    struct node*ptr,*q;
    ptr=p;
    while(ptr->link->link!=NULL)
    {
        ptr=ptr->link;
    }
    q=ptr->link;
    ptr->link=NULL;
    q->link=NULL;
    free(q);
    return p; 
}
struct node*deleteatbetween(struct node*p)
{
    int val;
    printf("\nEnter the element which you want to delete in between \n");
    scanf("%d",&val);
    struct node*ptr,*q;
    ptr=p;
    while(ptr->link->data!=val)
    {
        ptr=ptr->link;
    }
    q=ptr->link;
    ptr->link=q->link;
    q->link=NULL;
    free(q);
    printf("Linked List after deletion of elements in between\n");
    return p;
}
int main()
{
    int choice;
    struct node*temp,*last,*p;
    do
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->link=NULL;
        printf("Enter the number : ");
        scanf("%d",&temp->data);
        if(start==NULL)
        {
            start=temp;
            last=temp;
        }
        else
        {
            last->link=temp;
            last=temp;
        }
        printf("Enter your choice(1:Yes and 0: No) : ");
        scanf("%d",&choice);
    }while(choice!=0);
    traversal(start);
    start=insertatstart(start);
    traversal(start);
    start=insertatend(start);
    traversal(start);
    start=insertinbetween(start);
    traversal(start);
    start=deleteatstart(start);
    traversal(start);
    start=deleteatend(start);
    traversal(start);
    start=deleteatbetween(start);
    traversal(start);
    return 0;
}