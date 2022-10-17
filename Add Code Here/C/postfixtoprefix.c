#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
char str[MAX], stack[MAX];
int top = -1;
void push(char c)
{
  stack[++top] = c;
}
char pop()
{
  return stack[top--];
}
int checkIfOperand(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int isOperator(char x) 
{
  switch (x) 
  {
  case '+':
  case '-':
  case '/':
  case '*':
  return 1;
  }
  return 0;
}
void postfixToprfix() 
{
  int n, i, j = 0;
  char c[20];
  char a, b, op;
  printf("Postfix expression : \n");
  scanf("%s", str);
  n = strlen(str);
  for (i = 0; i < MAX; i++)
  stack[i] = '\0';
  printf("Prefix expression : \n");
  for (i = n - 1; i >= 0; i--)
  {
    if (isOperator(str[i]))
    {
      push(str[i]);
    } else
    {
      c[j++] = str[i];
      while ((top != -1) && (stack[top] == '#')) 
      {
        a = pop();
        c[j++] = pop();
      }
      push('#');
    }
  }
  c[j] = '\0';
  i = 0;
  j = strlen(c) - 1;
  char d[20];
  while (c[i] != '\0')
  {
    d[j--] = c[i++];
  }
  printf("%s\n", d);
}
int main() 
{
  postfixToprfix();
  return 0;
}

