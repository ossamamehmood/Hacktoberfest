#include<stdio.h>
int main()
{
	int n=5,i,j,a=1;
	for(i=1;i<=5;i++)
	{
		j=i;
		while(j!=0)
		{
			printf("%d ",a);
			j--;
			a++;
		}
		printf("\n");
	}
}
