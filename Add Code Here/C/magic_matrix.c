#include<stdio.h>
void main()
{
	int c=1,n,a[10][10]={0},ld=0,s=0,s1=0,i,j;
	printf("enter n between 3 to 10 :");
	scanf("%d",&n);
	i=0;
	j=n/2;
	while(c<=n*n)
	{
		//printf("now i=%d j=%d\n",i,j);
		if(i>=0 && j<n && a[i][j]==0){
			//		printf("inside now i=%d j=%d c=%d\n",i,j,c);
		a[i][j]=c;}
		else if(i<0 && j>n-1)
		{
			i=1;
			j=n-1;
			//printf("inside now i=%d j=%d c=%d\n",i,j,c);
			a[i][j]=c;
		}
		else if(i<0 && a[n-1][j]==0)
		{
					
			i=n-1;
		//	printf("inside now i=%d j=%d c=%d\n",i,j,c);
			a[i][j]=c;
		}
		else if(j>n-1 && a[i][0]==0)
		{
			j=0;
		//	printf("inside now i=%d j=%d c=%d\n",i,j,c);
			a[i][j]=c;
		}
		else if(i>=0 && j<n && a[i][j]!=0)
		{
			j=j-1;
			i=i+2;
		//	printf("inside now i=%d j=%d c=%d\n",i,j,c);

			a[i][j]=c;
		}
		i--;
		j++;
		c++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%3d ",a[i][j]);
		printf("\n");
	}
	printf("\n");	
	for(i=0;i<n;i++)
	{
		s=0;
		s1=0;
		for(j=0;j<n;j++)
		{
			s=s+a[i][j];
			s1=s1+a[j][i];
		}
		ld+=a[i][i];
		printf("sum of row%d is %d\n",i,s);
		printf("sum of col%d is %d\n",i,s1);
	}
	printf("Therefore sum of all rows, columns, diagonals is %d",ld);
}
