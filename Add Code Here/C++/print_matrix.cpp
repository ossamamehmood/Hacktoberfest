#include<stdio.h>
int main()
{
	int a[20][20],i,j,m,n;
	printf("Enter matrix size\n");
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
    }
    printf(" matrix \n");
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[j][i]);
		}
		printf("\n");
    }
}
