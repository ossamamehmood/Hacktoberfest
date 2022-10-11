#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h> 
#define size 100
char stack[size];
int top=-1;
void push(char data)
{
    if(top>=size-1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
    top=top+1;
    stack[top]=data;
    }
}
char pop()
{    
    char value;
    if(top<0)
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    else
    {
    value=stack[top];
    top=top-1;
    return value;
    }
    
}
int isOperator(char symbol)
{
     if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^')
     {
         return 1;
     }
     else{
         return 0;
     }
}
int precedence(char symbol)
{
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol=='*'||symbol=='/')
    {
        return 2;
    }
    else if(symbol=='+'||symbol=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
}
void InfixToPostfix(char infix_exp[size],char postfix_exp[size])
{
    char item,x;
    int i=0,j=0;
    item=infix_exp[i];
    push('(');
    strcat(infix_exp,")");
    while(item!='\0')
    {
        if(item=='(')
        {
            push('(');
        }
        else if(isdigit(item)||isalpha(item))
        {
            postfix_exp[j]=item;
            j++;
        }
        else if(isOperator(item)==1)
        {
            x=pop();
            while(isOperator(item)==1&&precedence(x)>=precedence(item))
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);

        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
        }
        
        i++;
        item = infix_exp[i];
    }
    if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}
    postfix_exp[j] = '\0'; 
}
int main()
{
    char infix[size],postfix[size];
    printf("Enter a Infix Expression :\n");
    scanf("%s",infix);
    InfixToPostfix(infix,postfix);                  
	printf("Postfix Expression: ");
	printf("%s",postfix);

}