// This is a program to find the factorial of any number using recursion

#include <stdio.h>
int factorial(int number)
{
    if (number == 1 || number == 0)
    {
        return 1;
    }
    else
    {
        return (number * factorial(number - 1));
    }
}
int main()
{
    int num;
    printf("enter the no. you want factorial of\n");
    scanf("%d", &num);
    printf("the factorial of %d is %d\n", num, factorial(num));

    return 0;
}
