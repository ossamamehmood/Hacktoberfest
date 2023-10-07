#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push a character onto the stack
void push(Stack *stack, char c) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = c;
}

// Function to pop a character from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char *input) {
    int length = strlen(input);
    Stack stack;
    initialize(&stack);

    // Push each character of the input string onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, input[i]);
    }

    // Pop characters from the stack and overwrite the input string
    for (int i = 0; i < length; i++) {
        input[i] = pop(&stack);
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
