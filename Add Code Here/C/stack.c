#include<stdio.h>
#define max 10
int st[max],top=-1;

void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main (){
    int val,option;
    do{
        printf("\n*****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. Size");
        printf("\n 5. Display");
        printf("\n 6. Exit");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch (option){
        case 1:
        printf("\n Enter the value to be pushed : ");
        scanf("%d",&val);
            push(st,val);
            break;
        case 2:
        val=pop(st);
        if(val!=-1){
            printf("\n The value deleted from the stack is %d",val);
        }
            break;
        case 3:
        val=peek(st);
        if(val!=-1){
            printf("\n The value at the top of stack is %d",val);
        }
            break;
        case 4:
        printf("Size of stack: %d",top+1);
        break;
        case 5:
            display(st);
            break;
        case 6:
            break;
        default:
        printf("Invalid Choice");
            break;
        }
    } while(option !=5);
    return 0;
}

void push(int st[],int val){
    if(top==max-1){
        printf("\n STACK OVERFLOW");
    }
    else{
        top++;
        st[top]=val;
    }
}

int pop(int st[]){
    int val;
    if(top==-1){
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else{
        val=st[top];
        top--;
        return val;
    }
}

int peek(int st[]){
    if(top==-1){
        printf("\n STACK EMPTY");
        return -1;
    }
    else{
        return st[top];
    }
}

void display(int st[]){
    if(top==-1){
        printf("\n STACK EMPTY");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d ",st[i]);
        }
    }
}