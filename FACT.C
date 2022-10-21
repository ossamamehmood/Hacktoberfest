#include<stdio.h>
int main()
{
 int i,number,fac=1;
 printf("Enter the no:");
 scanf("%d",&number);
 for(i=1;i<=number;i++)
 {
  fac*=i;
 }
 printf("factorial of given no.:%d",fac);
 }
