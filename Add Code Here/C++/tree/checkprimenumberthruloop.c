/* Program to check whether an entered number is prime or not 
by using the method of looping */


#include<stdio.h>
#include<conio.h>

void main()
{
    int num,i;
    printf("\n Enter the number");
    scanf("%d",&num);
    {
    if(num==1)
        {printf("\n 1 is neither a prime nor a composite number");}
    }
    i=2;
    while(i<=num-1)
    {
        if(num%i==0)
            {printf("\n Not a prime number");
            break;}
        i++;
    
    if(i==num)
        {printf("\n It is a prime number");}
    
    }
    getch();
}