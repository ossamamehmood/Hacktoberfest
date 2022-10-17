#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char st[MAX];
int top = -1;
char pop(char st[]);
void push(char st[], char c);
void infixtopostfix(char source[], char target[]);
int getpriority(char);
char *strrev(char *str)
{
    char c, *front, *back;
    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}
int main()
{
    char infix[100], prefix[100];
    printf("\nEnter any infix expression:\n");
    gets(infix);
    strcpy(prefix, "");
    strrev(infix);
    for(int i = 0; infix[i] != '\0'; i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';    
    }
    puts(infix);
    infixtopostfix(infix, prefix);
    strrev(prefix);
    printf("\nThe corresponding prefix expression is:\n");
    puts(prefix);
}
void infixtopostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\n INCORRECT EXPRESSION");
                exit(1);
            }
            temp = pop(st); 
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') && (getpriority(st[top]) > getpriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\nINCORRECT ELEMENT IN THE EXPRESSION");
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}
int getpriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;

    else if (op == '+' || op == '-')
        return 0;
}
void push(char st[], char val)
{
    if (top == (MAX - 1))
        printf("\nStack overflow");
    else
    {
        top++;
        st[top] = val;
    }
}
char pop(char st[])
{
    char val = ' ';
    if (top == -1)
        printf("\nStack underflow");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}
