#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int stack[SIZE];
int top = -1;  //top pointer of a stack
//int maxsize = 10;

int is_empty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(){
    if(top==SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

int push(int x){
    if(!is_full()){
        top++;
        stack[top]=x;
    }
    else{
        printf("Stack is full!!!");
    }
    return 0;
}

int pop(){
    int x;
    if(!is_empty()){
        x = stack[top];
        top--;
        return x;
    }
    else{
        printf("Stack is empty");
    }
    return 0;
}

int main(){
    while (1){
    printf("Enter the operation to perform:\n1.PUSH\n2.POP\n3.DISPLAY STACK\n4.EXIT:\nEnter Choice: ");
    int choice;
    scanf("%d",&choice);

    if(choice == 1){
        int num;
        printf("Enter the element: ");
        scanf("%d",&num);
        push(num);
    }

    else if(choice == 2){
        pop();
    }

    else if(choice == 3){
        while (!is_empty()){
            int x = pop();
            printf("%d\n",x);
        }
    }

    else if(choice == 4) {
        printf("Exit Successfully");
        exit(0);
    }

    else{
        printf("Wrong Choice!!!");
    }

    return 0;
}
}