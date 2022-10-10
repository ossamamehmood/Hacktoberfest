#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_at_beg(struct node *);
struct node *insert_at_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node*);
struct node *del_beg(struct node*);
struct node *del_end(struct node*);
struct node *del_after(struct node*);
struct node *del_before(struct node*);
int main(void)
{
    struct node *start=NULL;
    int option;
    printf("Roll No:- 191223");
    while(1)
    {
        printf("\n________MAIN MENUE FOR CIRCULAR LL________ \n Choose your option :- \n");
        printf("1. Create a list.\n2. Display list.\n3. Insert new node at beginning.\n4. Insert new node at the end. \n5. Insert after a given value.\n6. Insert before a given value.\n");
        printf("7. Delete at beginning.\n8. Delete at end.\n9.Delete after a value.\n10.Delete before a value.\n11. Press 0 to exit.\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            start=create_ll(start);
            printf("Link List created.");
            break;
        case 2:
            start=display(start);
            break;
        case 3:
            start=insert_at_beg(start);
            break;
        case 4:
            start=insert_at_end(start);
            break;
        case 5:
            start=insert_after(start);
            break;
        case 6:
            start=insert_before(start);
            break;
        case 7:
            start=del_beg(start);
            break;
        case 8:
            start=del_end(start);
            break;
        case 9:
            start=del_after(start);
            break;
        case 10:
            start=del_before(start);
            break;
        case 0:
            exit(0);

        }
    }
    return 0;
}
struct node *create_ll(struct node *start)
{
   struct node *new_node,*prenode;
   struct node *ptr;
    int num,n,i;
    printf("enter the number of node");
    scanf("%d",&n);
    if(n>=1)
    {
        //creates and links the head node//
        start=(struct node *)malloc(sizeof(struct node));
        printf("Enter data of node 1:");
        scanf("%d",&num);
        start->data=num;
        start->next=NULL;
        prenode=start;
    }
    //creates links of n-1 nodes
    for(i=2;i<=n;i++)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data of %d node",i);
        scanf("%d",&num);
        new_node->data=num;
        new_node->next=NULL;
        //link previous node to new node
        prenode->next=new_node;
        //move previous node shead
        prenode=new_node;
    }
    prenode->next=start;
    printf("\nCircular link list created\n");
    return start;
}
struct node *display(struct node *start)    //display contents of list
{
    struct node *ptr=start;
    printf("Link List is:\n");
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(ptr->next!= start)
        {
            printf(" %d <-->",ptr->data);
            ptr=ptr->next;
        }
        printf(" %d ",ptr->data);
    }
  return start;
}
struct node *insert_at_beg(struct node *start)
{
    int num;
    struct node *newnode;
    struct node *ptr=start;
    if(start==NULL)
    {
        printf("\t List is empty");
    }
    printf("\nEnter the data of the new node: ");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node *));
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    newnode->data=num;
    newnode->next=start;
    ptr->next=newnode;
    start=newnode;
    display(start);
    return start;
}
struct node *insert_at_end(struct node *start)
{
    struct node *newnode;
    int num;
    printf("\nEnter the data of the new node:");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=num;
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=start;
    display(start);
    return start;
}
struct node *insert_after(struct node *start)
{
    struct node *newnode, *ptr, *preptr;
    int num,val;
    printf("\nEnter the data of the new node:");
    scanf("%d",&num);
    printf("\nEnter the number after which you want to insert:");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=num;
    ptr=start;
    preptr=ptr;
    while(ptr->data!=val)
    {
       // preptr=ptr;
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    display(start);
    return start;
}
struct node *insert_before(struct node *start)
{
    struct node *newnode, *ptr, *preptr;
    int num,val;
    printf("\nEnter the data of the new node:");
    scanf("%d",&num);
    printf("\nEnter the number before which you want to insert:");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=num;
    ptr=start;
    preptr=ptr;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    display(start);
    return start;

}
struct node *del_beg(struct node *start)
{
    struct node *preptr=start,*ptr=start;
    if(start==NULL)
    {
        printf("List is empty");
        exit(0);
    }
    while(preptr->next!=start)
    {
        preptr=preptr->next;
    }
    start=ptr->next;
    preptr->next=start;
    free(ptr);
    display(start);
    return start;
}
struct node*del_end(struct node *start)
{
    struct node *ptr=start,*preptr=start;
    if(start==NULL)
    {
        printf("List is empty");
        exit(0);
    }
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=start;
    free(ptr);
    display(start);
    return start;
}
struct node *del_after(struct node *start)
{
    struct node *ptr=start;
    struct node *preptr=start;
    int num;
    if(start==NULL)
    {
        printf("List is empty");
        exit(0);
    }
    printf("Enter the value after which you want to delete : ");
    scanf("%d",&num);
    while(preptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    display(start);
    return start;
}
struct node *del_before(struct node *start)
{
    struct node *ptr=start;
    struct node *preptr=start;
    struct node *pre_preptr=start;
    int num;
    if(start==NULL)
    {
        printf("List is empty");
        exit(0);
    }
    printf("Ënter the value before which you want to delete");
    scanf("%d",&num);
    while(ptr->data!=num)
    {
        pre_preptr=preptr;
        preptr=ptr;
        ptr=ptr->next;
    }
    pre_preptr->next=ptr;
    free(preptr);
    display(start);
    return start;
}



