#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

// Initialize the stack
void initialize(Stack *stack) {
    stack->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    stack->size = 0;
    stack->capacity = INITIAL_CAPACITY;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->size == 0;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->size == stack->capacity) {
        // Double the capacity when the stack is full
        stack->capacity *= 2;
        stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[stack->size++] = value;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // You can choose a different error value if needed
    }
    return stack->data[--stack->size];
}

// Peek at the top element of the stack without removing it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // You can choose a different error value if needed
    }
    return stack->data[stack->size - 1];
}

// Free the memory used by the stack
void cleanup(Stack *stack) {
    free(stack->data);
    stack->size = 0;
    stack->capacity = 0;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Is stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    cleanup(&stack);

    return 0;
}
