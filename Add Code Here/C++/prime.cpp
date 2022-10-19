#include<stdio.h>
int main()
{
	int n,i,res=1;
	printf("Enter number: ");
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			res=i;
		}
	}
	if(res==1)
 	{
 		printf("prime");
	 }
	else
	{
 		printf("not a prime");
	 }
}
