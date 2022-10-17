#include<stdio.h>
int sod(int n);
int getluckynumber(int n);
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",getluckynumber(n));
}
    int sod(int n)
{
	int sum,rem;
	sum=0;
	while(n!=0)
	{
		rem=n%10;
		sum+=rem;
		n/=10;
	}
	return sum;
}
	int getluckynumber(int n)
   {
		int l=sod(n);
		if(l<10)
		return l;
		else
		return getluckynumber(l);
		
	}
	
