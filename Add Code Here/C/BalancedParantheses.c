#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
struct lifo{
    char x[MAXSIZE];
    int top;
};
typedef struct lifo stack;
stack s;

void createStack(stack *s){
    s->top = -1;
}

void push(stack *s,char a){
    if(s->top == MAXSIZE-1){
        printf("\nThe Stack is Full");
        exit(-1);
    }
    else{
        s->x[s->top + 1]='a';
        s->top++;
    }

}

char pop(stack *s){
    if(s->top = -1){
        printf("\nUNDERFLOW");
    }
    else{
        return s->x[s->top];
    }
    
}

void Balanced(stack *s){

}
void isEmpty(stack *s){

}

int main(){
    stack bp;
    char str[MAXSIZE];
    printf("\nEnter the expression : ");
    scanf("%s",str);
    createStack(&bp);
    for(int i=0;i<(MAXSIZE-1);i++){
    if(str[i]=='(' || str[i]=='{' || str[i]=='['){
        push(&bp,str[i]);
    }
    else if(str[i]==')' || str[i]=='}' || str[i]==']'){
        if(str[i]== bp.x[bp.top]){
            pop(&bp);
        }
        else{
            printf("\nWrong Input");
            break;
        }
        
    }
    
    
    }
    printf("\nThe Expression is not balanced");








    return 0;
}
