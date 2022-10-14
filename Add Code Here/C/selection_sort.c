#include <stdio.h> 
void swap(int *a,int *b) 
{ 
	int temp=*a; 
	*a=*b; 
	*b=temp; 
} 
void selectionSort(int a[],int n) 
{ 
	int i,j,min; 
	for (i=0;i<n-1;i++) 
	{ 
		min=i; 
		for (j=i+1;j<n;j++) 
		if (a[j]<a[min]) 
			min=j; 
		swap(&a[min],&a[i]); 
	} 
} 
int main()
{
   int n,i;
   printf("Enter the total number element in Array:\n");
   scanf("%d",&n);
   int a[n];
   printf("Enter the Array element in Array:\n");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   selectionSort(a,n);
   printf("sorted Array element:\n");
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   return 0;
}
