#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack {
    int top;
    unsigned capacity;
    char* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}


char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; 
}


void reverseString(char* input) {
    int len = strlen(input);

    
    struct Stack* stack = createStack(len);

    
    for (int i = 0; i < len; i++) {
        push(stack, input[i]);
    }

    
    for (int i = 0; i < len; i++) {
        input[i] = pop(stack);
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}
