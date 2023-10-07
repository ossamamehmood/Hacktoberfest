#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack using an array
struct Stack
{
    int size;     // Maximum size of the stack
    int top;      // Index of the top element in the stack
    int *S;       // Array to store stack elements
};

// Function to create a stack with the given size
void create(struct Stack *st, int s)
{
    st->size = s;
    st->top = -1;            // Initialize the top index to -1 (empty stack)
    st->S = (int *)malloc(s * sizeof(int)); // Allocate memory for the stack array
}

// Function to display the elements of the stack
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]); // Print each element in the stack
        printf("\n");
    }
}

// Function to push an element onto the stack
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n"); // Check if the stack is full
    else
    {
        st->top++;            // Increment the top index
        st->S[st->top] = x;   // Push the element onto the stack
    }
}

// Function to pop an element from the stack
int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack Underflow\n"); // Check if the stack is empty
    else
    {
        x = st->S[st->top]; // Pop the top element from the stack
        st->top--;         // Decrement the top index
    }
    return x;
}

// Function to peek at the top element of the stack
int peek(struct Stack st)
{
    int x = st.S[st.top]; // Get the top element of the stack
    return x;
}

// Function to check if the stack is empty
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1; // Return 1 if the stack is empty, else return 0
    return 0;
}

// Function to check if the stack is full
int isFull(struct Stack st)
{
    return st.top == st.size - 1; // Return 1 if the stack is full, else return 0
}

// Function to get the top element of the stack without removing it
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top]; // Return the top element if the stack is not empty
    return -1;
}

int main()
{
    struct Stack st;
    create(&st, 10); // Create a stack of size 10

    push(&st, 10); // Push elements onto the stack
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    Display(st); // Display the elements in the stack

    printf("peek: %d ", peek(st)); // Peek at the top element of the stack

    return 0;
}
