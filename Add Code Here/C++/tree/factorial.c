#include<stdio.h>
int main()
{
    
    int n,fact=1;
    scanf("%d",&n);//get the integer input from the user
    while(n!=0)//checking the condition
    {
        fact=fact*n;
        n--;
    }
    printf("Factorial of the given integer = %d",fact);//printing the final answer
}