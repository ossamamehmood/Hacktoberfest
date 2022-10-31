#include<stdio.h>
#include<conio.h>
long factorial(int);
int main()
{
 int num;
 long fact=1;
 clrscr();
 printf("Enter a number: ");
 scanf("%d",&num);
 fact=factorial(num);
 printf("Factorial=%ld",fact);
 getch();
 return 0;
}
long factorial(int n)
{
 if(n==0 || n==1)
  return 1;
 else
  return n*factorial(n-1);
}


