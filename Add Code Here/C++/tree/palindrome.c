#include<stdio.h>
#include<conio.h>
void main()
{
	int n,x,r=0,t;
	printf("Enter the number you want to check" );
	scanf("%d",&n);
	t=n;
	while(n!=0)
	{
		x=n%10;
		r=r*10+x;
		n/=10;
	}
	if (t==r)
	{
		printf("Palindrome");
	}
	else
	{
		printf("Not Palindrome");
	}
	
getch();
}
