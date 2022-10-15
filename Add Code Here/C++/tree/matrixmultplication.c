#include <stdio.h>
#include <conio.h>
void main()
{

	int a[50][50],b[50][50],c[50][50],r1,r2,c1,c2,i,j,k;
	printf("Enter the order of martix 1: \n");
	scanf("%d%d",&r1,&c1);
	printf("Enter the order of matrix 2: \n");
	scanf("%d%d",&r2,&c2);
	printf("Enter the elements of matrix 1: \n");
	for (i = 1; i <= r1; i++)
	{
		for(j = 1; j <= c1; j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter the elements of matrix 2: \n");
	for (i = 1; i <= r2; i++)
	{
		for (j = 1; j <= c2; j++)
			scanf("%d",&b[i][j]);
	}
	if(r2==c1)
	{
		for (i = 1; i <= r1; i++)
		{
			for (j = 1; j <= c2; j++)
			{
				c[i][j]=0;
				for (k = 1; k <= c1; k++)
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}	
		printf("Product of the matrix is: \n", );
		for (i = 1; i <= r1; i++)
		{
			for (j = 1; j <= c2; j++)
				printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
	else
		printf("Multiplication is Not Possible");
	getch();
}