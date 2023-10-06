#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

int stack[MAX_SIZE]; // initialise the stack
int top = -1;        // top element


//Basic Oparation of Stack
bool isEmpty(){
   return top == -1;
}
bool isFull(){
    return top == MAX_SIZE -1;
}

void Push(int data){
    if(isFull()){
        printf("Stack is Full. can not add data %d\n", data);
        return ;
    }
    printf("Added data %d\n",data);
    stack[++top] = data;
}

int Pop(){
    if(isEmpty()){
       printf("Stack is Empty. can not pop\n");
       return -1; // an error code
    }
    printf("Poped data %d\n",stack[top]);
    return stack[top--];
}


int main(){
    Push(2); // Pushing Element
    Push(3);
    Push(1);
    Pop();   //poping
    Push(23);
    Pop();
}


