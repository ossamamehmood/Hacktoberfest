//implimentation of stack using array
#include <stdio.h>
int top=-1;
int push(int stack[],int size)
{
    if((size-1)<=top)
    {
       printf("The stack is full\n");
    }
    else
    {
        top++;
        printf("Ënter data\n");
        scanf("%d",&stack[top]);
    }
    return 0;
}
int pop(int stack[])
{
    if(top>-1)
    {
        printf("%d\n",stack[top]);
        top--;
    }
    else
    printf("The stack is empty\n");
    return 0;
}
int main()
{
    int len,op=0;
    printf("Enter the size of stack\n");
    scanf("%d",&len);
    int stack[len];
    while(op!=3)
    {
        printf("Enter 1 to push 2 to pop 3 to exit\n");
        scanf("%d",&op);
        if(op==1)
        push(stack,len);
        else
        pop(stack);
    }
    return 0;
}