#include <stdio.h>
#include <conio.h> // Note: conio.h is not a standard C library; it's typically used in DOS/Windows environments for console I/O.

#define Max 5
int a[Max], top = -1;

// Function to push an element onto the stack
void push();

// Function to pop an element from the stack
void pop();

// Function to display the elements in the stack
void display();

int main()
{
    int ch;
    printf("1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\n4. End program");
    
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice");
        }
    }
}

void push()
{
    int data;
    if (top == Max - 1)
    {
        printf("\nStack is full");
    }
    else
    {
        printf("\nEnter element to be pushed: ");
        scanf("%d", &data);
        top++;
        a[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nPopped element: %d", a[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top >= 0)
    {
        printf("\nElements: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", a[i]);
        }
    }
    else
    {
        printf("\nStack is empty");
    }
}
