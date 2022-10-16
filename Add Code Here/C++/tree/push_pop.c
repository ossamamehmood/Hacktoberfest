#include <stdio>
#include <stdlib>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int x)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void pop()
{
    struct node *temp = top;
    if (top == NULL)
        printf("Stack is Underflow\n");

    printf("\nPop element is %d \n", top->data);
    top = temp->next;
    free(temp);
}
void peek()
{
    if (top == NULL)
        printf("Stack is Empty\n");
á¹‡á¹‡
    printf("Top element is %d", top->data);
}
void show()
{
    struct node *temp = top;
    if (top == NULL)
        top = temp;

    printf("Element are:");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    show();
    pop();
    show();
    return 0;
}