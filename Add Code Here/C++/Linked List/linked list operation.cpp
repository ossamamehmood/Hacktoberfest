
#include <stdio.h>
#include <stdlib.h>
struct node* head;
struct node* ptr;
struct node* prev;
int item;
int key;
struct node
{
    int data;
    struct node* link;
    struct node* ptr;
    struct node* prev;
    struct node* head;
};
void insert_front()
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("*!memory allocation failed.insertion not possible!*");
        
    }
    else
    {
     printf("enter the item to insert : ");
     scanf("%d",&item);
    
    new->data=item;
    new->link=head;
    head=new;
    }
}
void insert_end()
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("*!memory allocation failed.insertion not possible!*");
        
    }
    else
    {
        printf("enter the item to insert : ");
        scanf("%d",&item);
        new->data=item;
        new->link=NULL;
        ptr=head;
        while(ptr!=NULL)
        {
            ptr=ptr->link;
            ptr->link=new;
        }
    }
}
void insert_anyposition()
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("*!memory allocation failed.insertion not possible!*");
        
    }
    else
    {
        printf("enter the item to insert : ");
        scanf("%d",&item);
    
        new->data=item;
        ptr=head;
        printf("enter the value of key : ");
        scanf("%d",&key);
        while(ptr->data!=key)
        {
            ptr=ptr->link;
            new->link=ptr->link;
            ptr->link=new;
        }
    }
}
void delete_front()
{
    ptr=head;
    printf("%d is deleted",ptr->data);
    head=head->link;
    free(ptr);
    
}
void delete_end()
{
    ptr=head;
    while(ptr->link!=NULL)
    {
        prev=ptr;
        ptr=ptr->link;
        printf("%d is deleted",ptr->data);
        prev->link=NULL;
        free(ptr);
    }
}
void delete_anyposition()
{
    if(ptr==NULL)
    {
        printf("*!element not found!*");
        
    }
    else
    {
        
    
        printf("enter the value of key : ");
        scanf("%d",&key);
        int data=key;
        while((ptr->data!=key)&&(ptr!=NULL))
        {
            prev=ptr;
            ptr=ptr->link;
            prev->ptr=ptr->link;
            printf("%d is deleted",ptr->data);
            free(ptr);
        }
    }
}   
void printlist()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

}
int main()
{
    struct node* head=NULL;
    int item;
    int choice;
    while(1)
    {
        printf("operations in linke list: ");
        printf("\n1-Insertion at front \n  2-Insertion at end \n 3-Insertion at any point\n 4-Deletion at front\n 5-Deletion at back\n 6-Deletion at any point\n 7-To traverse a linked list\n 8-exit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("INSERTION AT FRONT...");
            insert_front();
            break;
            case 2:printf("INSERTION AT END ....");
            insert_end();
            break;
            case 3:printf("INSERTION AT ANY POSITION...");
            insert_anyposition();
            break;
            case 4:printf("DLETION AT FRONT....");
            delete_front();
            break;
            case 5:printf("DELETION AT BACK....");
            delete_end();
            break;
            case 6:printf("DELETION AT ANY POSITION....");
            delete_anyposition();
            break;
            case 7:printf("TO TRAVERSE(PRINT)LINKEDLIST....");
            printlist();
            break;
            case 8:exit(0);
            break;
            default:printf("invalid choice");
            break;
        }
    }
return 0;
}


