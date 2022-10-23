//implimentation of stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* top;
int i_top=-1;
struct node* push (struct node* top,int size)
{
    if(i_top>=size-1)
    {
        printf("Stack is full\n");
        return top;
    }
    else
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node()));
        i_top++;
        temp->next=top;
        printf("Enter data\n");
        scanf("%d",&temp->data);
        return temp;
    }
}
void pop()
{
    struct node* free_ptr=top;
    if(i_top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("%d\n",top->data);
        top=top->next;
        i_top--;
        free(free_ptr);
    }
}
int main()
{
    int size,op=0;
    printf("Enter the size of the stack\n");
    scanf("%d",&size);
    while(op!=3)
    {
        printf("Press\n1 to push\n2 to pop\n3 to exit\n");
        scanf("%d",&op);
        if(op==1)
        {
            top=push(top,size);
        }
        else if(op==2)
        {
            pop();
        }
    }
    return 0;
}