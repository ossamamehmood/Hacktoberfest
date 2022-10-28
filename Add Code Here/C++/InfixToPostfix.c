#include <stdio.h>
#include <ctype.h>
char s[100];
int top = -1;
void push(char x)
{
    top = top + 1;
    s[top] = x;
}
char pop()
{
    char x;
    if (top == -1)
    {
        return -1;
    }
    else
    {
        x = s[top];
        top = top - 1;
        return x;
    }
}
int precedence(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '^')
    {
        return 3;
    }
    return 0;
}
int main()
{
    char e[100];
    char *t, x;
    printf("**21BKT0132- Tanisha Choudhary** Enter infix expression:\n");
    scanf("%s", e);
    t = e;
    printf("**21BKT0132- Tanisha Choudhary* The postfix expression is:\n");
    while (*t != '\0')
    {
        if (isalnum(*t))
        {
            printf("%c", *t);
        }
        else if (*t == '(')
        {
            push(*t);
        }
        else if (*t == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (precedence(s[top]) >= precedence(*t))
            {
                printf("%c", pop());
            }
            push(*t);
        }
        t++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}
