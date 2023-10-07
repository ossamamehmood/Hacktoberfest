#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct node
{
    int data;
    struct node *next;
};

// Define a pointer 'top' to represent the top of the stack
struct node *top = NULL;

typedef struct node node;

// Function to push an element onto the stack
void push(int x)
{
    node *t;
    t = (node *)malloc(sizeof(node));

    if (t == NULL)
        printf("stack is full\n"); // Check if memory allocation failed
    else
    {
        t->data = x;       // Set the data of the new node
        t->next = top;     // Set the next pointer of the new node to the current top
        top = t;           // Update 'top' to point to the new node
    }
}

// Function to pop an element from the stack
int pop()
{
    node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is Empty\n"); // Check if the stack is empty
    else
    {
        t = top;        // Set 't' to point to the current top node
        top = top->next; // Update 'top' to point to the next node
        x = t->data;    // Get the data from the top node
        free(t);        // Free the memory of the popped node
    }
    return x;
}

// Function to display the elements of the stack
void Display()
{
    node *p;
    p = top;

    while (p != NULL)
    {
        printf("%d  ", p->data); // Print the data of each node
        p = p->next;             // Move to the next node
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(10);
    push(20);
    push(30);

    printf("Printing the linked list:\n");
    Display(); // Display the elements in the stack

    printf("\nAfter pop operation:\n");
    printf("%d ", pop()); // Pop an element from the stack and print it

    return 0;
}
