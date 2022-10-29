#include<stdio.h>
int main()
{
	int a[100],i,n,pos;
	printf("enter no. of elements in array");
	scanf("%d",&n);
	
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("before deletion");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	
	printf("\n enter position which you want to delete");
	scanf(" %d",&pos);
	
	for(i=pos;i<n-1;i++)
	a[i]=a[i+1];
	
	printf("after deletion");
	for(i=0;i<n-1;i++)
	printf("\n %d",a[i]);
	
	return 0;
}
