#include<stdio.h>

fib(int n)
{
	int m,k,s;
	if( n==0 || n==1 )
	{
		return n;
	}
	m=fib(n-1);
	k=fib(n-2);
	s=m+k;
	return s;
}

void main()
{
	int i,j;
	printf("Enter number of elements in sequence:\n");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		printf("%d ",fib(j));
	}
	
}
