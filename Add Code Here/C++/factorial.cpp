#include<stdio.h>
int fact(int n)
{
	int res=1,i;
	if(n==0||n==1)
		return 1;
	else
	{
		for(i=1;i<=n;i++)
			res*=i;
	}
	return res;		
}
int main()
{
	int n,res;
	scanf("%d",&n);
	res=fact(n);
	printf("factorial is :%d",res);
}

