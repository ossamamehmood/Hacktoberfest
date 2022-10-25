#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*temp;
    struct node* head=0;
//functionToFindNumberOfNodes
int length()
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    printf("length is %d \n",count);
    return count;
}
    
//functionToInsertFromBeginning
void insertbeg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
        display();
}       

//functionToInsertFromEnd
void insertend()
{
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=head;
        while(temp->next !=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        display();
}

//functionToInsertAtAnyPosition
void insertpos()
{
    int pos, item, i = 1;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position at which INSERTION has to be done \n ");
    scanf("%d", &pos);
    printf("\nEnter the ITEM to be inserted \n");
    scanf("%d", &newnode->data);
    temp=head;
    newnode->next=0;
    int l=length();
    if(pos>l)
        {
            printf("Invalid position \n");
        }
    else
        {
          while (i < pos - 1) 
            {
                temp = temp->next;
                i++;
            }
          newnode->next = temp->next;
          temp->next =newnode;
          printf("\nItem inserted\n");
        } 
        display();
    }

//functionToDeleteFromFront
void deletefront()
{ 
     if (head == NULL)
        printf("\nList is empty\n");
        else 
    {
        temp = head;
        head = head->next;
        int x = temp->data;
        printf("\nDeleted item is  %d \n",x);
        free(temp);
    }
    display();
}

//functionToDeleteFromEnd
void deleteend()
{
    struct node *temp, *prevnode;
    if (head == NULL)
        printf("\nList is Empty\n");
    else 
        {
        temp = head;
        while (temp->next != 0) 
         {
            prevnode = temp;
            temp = temp->next;
         }
         int x = temp->data;
         printf("\nDeleted item is %d \n",x);
         free(temp);
         prevnode->next = 0;
        }
        display();
}

//functionToDeleteFromAnyPosition
void deletepos()
{
    struct node *temp, *position;
    int i = 1, pos;
    if (head == NULL)
        printf("\nList is empty\n");
    else 
    {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = head;
        int l=length();
        if(pos<1 || pos>l)
        {
            printf("\tInvalid Position");
        }
        else
          {
             if(pos==1)
              {
                  deletefront();
              }
             else
              {
                while (i < pos - 1)
                {
                temp = temp->next;
                i++;
                }
                position = temp->next;
                temp->next= position->next;
                int x = position->data;
                printf("\nDeleted item is %d \n",x);
                free(position);
                }
            }
    }   
    display();
}

//functionToDisplayLinkedList
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//mainFunctin
int main()
{
    int choice;
    //LinkedListCreation
    while(choice)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
            {
                head=temp=newnode;
            }
        else
            {
                temp->next=newnode;
                temp=newnode;
            }
        printf("Do you want to contnue(0,1)?");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp!=0)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    int opt;
    printf("\nLinked List Operations\n");
    while (1) 
    {
        printf("\t1 Insertion at beginning\n");
        printf("\t2 Insertion at end\n");
        printf("\t3 Insertion at any position\n");
        printf("\t4 Deletion at begining\n");
        printf("\t5 Deletion at end\n");
        printf("\t6 Deletion of element at any position\n");
        printf("\t7 Display the list\n");
        printf("\t8 To exit\n");
        printf("\nEnter Option :");
        scanf("%d", &opt);
        switch (opt) 
        {
            case 1:insertbeg();
                   break;
            case 2:insertend();
                   break;
            case 3:insertpos();
                   break;
            case 4:deletefront();
                   break;
            case 5:deleteend();
                   break;
            case 6:deletepos();
                   break;
            case 7:display();
                   break;
            case 8:exit(1);
                   break;
            default:printf("Incorrect Option\n");
        }
    }
    return 0;
}
