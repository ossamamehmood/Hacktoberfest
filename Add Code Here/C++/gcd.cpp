#include<stdio.h>
int gcd(int a,int b);
int main()
{
	int a,b,res;
	scanf("%d %d",&a,&b);
	res=gcd(a,b);
	printf("gcd is %d",res);
}
int gcd(int a,int b)
{
	int res=0,i;
	if(a>b)
	{
		for(i=1;i<=a;i++)
		{
			if(a%i==0)
			{
				if(b%i==0)
					res=i;
			}
		}
	}
	else
	{
		for(i=1;i<=b;i++)
		{
			if(a%i==0)
			{
				if(b%i==0)
					res=i;
			}
		}
	}
	return res;
}
