// this header file is for C lang, try not to use with c++ as it might generate some errors
#ifndef __STACK_LINKEDLIST__
#define __STACK_LINKEDLIST__ 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack // outer struct to use as Stack
{
    size_t length; // var to store length of stack

    struct Internal
    { // inner struct to use as stack nodes
        int data;
        struct Internal *prev, *next;
    } * top, *temp;

} Stack;

typedef enum
{
    false,
    true
} bool;
// enum for boolean variable, to maintain backward compatibilty
//      with c98 and c89, i skipped <stdbool.h>, feel free to
//      include it if you use c99 or later

// function declaration

Stack *getNewStack(void);
// function to allocate memory for new stack
// takes nothing
// returns a pointer of type Stack

Stack *push(Stack *stk, const int value);
// function to add an element in stack
// takes a poiner of type Stack and int value
// returns pointer to updated stack

Stack *pop(Stack *stk);
// function to remove last elemment of stack
// takes a pointer to stack
// return a pointer to updated stack

const int peek(const Stack *stk);
// function to get last element of stack
// takes a constant pointer to stack
// return a constant inteager value

const int length(const Stack *stk);
// function to get length of stack
// takes a constant pointer to stack
// return a constant inteager value

const bool stackNull(const Stack *stk);
// function to check if given stack pointer is null
// takes a constant pointer of Stack type
// return boolean, or it's integer equivalent

// function defination

Stack *getNewStack(void)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));

    if (temp == NULL)
    {
        printf("Error : Memory allocation failed !\n");
        return NULL;
    }

    // assigning default value to it's internal element
    temp->length = 0;
    temp->temp = temp->top = NULL;
    // no more wild pointer

    return temp;
}

Stack *push(Stack *stk, const int value)
{
    stk->temp = (struct Internal *)malloc(sizeof(struct Internal));
    // allocating memory for internal structure

    stk->temp->data = value;
    stk->temp->next = stk->temp->prev = NULL;
    // putting value and nullifying wild pointers

    if (stk->top == NULL)     // if no element exists
        stk->top = stk->temp; // then this is first and top element
    else
    {
        stk->top->next = stk->temp;
        stk->temp->prev = stk->top;
        stk->top = stk->temp;
    }

    /* this part can be optimised by and reduced by 2 or 3 lines,
        but doing so will reduce readability for beginners
        but if you can, feel free to optimise it and send pull request
    */

    ++stk->length;

    return stk;
}

Stack *pop(Stack *stk)
{
    if (stackNull(stk))
        return stk;

    stk->temp = stk->top;
    stk->top = stk->top->prev;
    free(stk->temp);

    --stk->length;

    return stk;
}

const int peek(const Stack *stk)
{
    if (stackNull(stk))
        return -1;

    return stk->top->data;
}

const int length(const Stack *stk)
{
    if (stackNull(stk))
        return -1;

    return stk->length;
}

const bool stackNull(const Stack *stk)
{
    if (stk == NULL)
    {
        printf("Error : Stack empty or doesn't exist!\n");
        return true;
    }

    return false;
}

#endif
