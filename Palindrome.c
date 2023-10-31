#include<stdio.h>
void main()
{
  int n,rem,rev=0;

  printf("Enter a number= ");
  scanf("%d",&n);

  int a=n;
  while(a>0)
  {
    rem=a%10;
    rev=rev*10 + rem; 
    a=a/10;
  }

  if(n==rev)
  {
    printf("%d is a palindrome",n);
  }
  else
  {
     printf("%d is not a palindrome",n);
  }
}
