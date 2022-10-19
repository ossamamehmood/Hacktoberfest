#include <stdio.h>
#include <string.h>

int stack[500], top, x, len, i;
int top = -1;
int flag = 0;
int cur_counter = 0;
int squ_counter = 0;
int reg_counter = 0;
int ang_counter = 0;

void cat_test(int counter)
{
    if (counter < 5)
    {
        printf(" - Insufficient\n");
    }
    else if (counter >= 5 && counter <= 10)
    {
        printf(" - Moderate\n");
    }
    else if (counter > 10)
    {
        printf(" - Sufficient\n");
    }
}

int main()
{
    char text[5000];

    printf("Text: ");
    scanf("%s", &text);

    len = strlen(text);

    for (i = 0; i < len; i++)
    {
        if (text[i] == '{' || text[i] == '[' || text[i] == '(' || text[i] == '<')
        {
            x = text[i];
            top++;
            stack[top] = x;
        }

        if (text[i] == '}' || text[i] == ']' || text[i] == ')' || text[i] == '>')
        {
            if (text[i] == '}' && stack[top] == '{')
            {
                top--;
                cur_counter = cur_counter + 1;
            }
            else if (text[i] == ']' && stack[top] == '[')
            {
                top--;
                squ_counter = squ_counter + 1;
            }
            else if (text[i] == ')' && stack[top] == '(')
            {
                top--;
                reg_counter = reg_counter + 1;
            }
            else if (text[i] == '>' && stack[top] == '<')
            {
                top--;
                ang_counter = ang_counter + 1;
            }
            else
            {
                printf("The parenthesis are not balanced.");
                flag = -1;
            }
        }
    }

    if (top == -1)
    {
        printf("The parenthesis are balanced.\n");

        printf("Number of pairs of curly brackets: %d", cur_counter);
        cat_test(cur_counter);

        printf("                  square brackets: %d", squ_counter);
        cat_test(squ_counter);

        printf("                 regular brackets: %d", reg_counter);
        cat_test(reg_counter);

        printf("                 angular brackets: %d", ang_counter);
        cat_test(ang_counter);
    }
    else if (flag == 0)
    {
        printf("The parenthesis are not balanced.\n");
    }
}
