#include<stdio.h>
int main()
{
	int n=5,i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==1||i==2||i==3)
			{
			if(j==1||j==2||j==3)
			{
				printf("  ");
				continue;
			}
			else
			{
			printf("* ");
		    }
		    }
			else
			{
			printf("* ");
		    }
		}
			printf("\n");
	}
}
