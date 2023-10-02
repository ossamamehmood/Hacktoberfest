#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

int precedence(char);
void push(char);
char pop();

int main()
{
  char str[20] = "x^y/(a*z)+b";
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (isalpha(str[i]))
    {
      printf("%c", str[i]);
    }
    else if (str[i] == '(')
    {
      push(str[i]);
    }
    else if (str[i] == ')')
    {
      while (top >= 0 && stack[top] != '(')
      {
        printf("%c", pop());
      }
      if (top >= 0 && stack[top] == '(')
      {
        pop(); // Pop the '(' from the stack
      }
    }
    else
    {
      while (top >= 0 && precedence(stack[top]) >= precedence(str[i]))
      {
        printf("%c", pop());
      }
      push(str[i]);
    }
  }

  while (top >= 0)
  {
    printf("%c", pop());
  }

  return 0;
}

int precedence(char symbol)
{
  if (symbol == '^')
    return 3;
  else if (symbol == '*' || symbol == '/')
    return 2;
  else if (symbol == '+' || symbol == '-')
    return 1;
  else
    return 0;
}

void push(char item)
{
  stack[++top] = item;
}

char pop()
{
  return stack[top--];
}