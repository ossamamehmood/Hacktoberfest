#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000

int top=-1, count=0;
char stack[max];
char output[max];

void push(char);
void pop();

int main(){
    char str[max];
    printf("Enter the string:\n");
    gets(str);

    for (int i = 0; i < strlen(str); i++)
    {
       push(str[i]);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        pop();
    }

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c",output[i]);
    }
     
    return 0;

}

void push(char t)
{
     if (top == max-1)
     {
        printf("\nOverflow\n");
     }
     else
     {
        top++;
        stack[top]=t;
     }
     
}

void pop()
{
    if (top==-1)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        output[count] = stack[top];
        top--;
        count++;
    }
    
}