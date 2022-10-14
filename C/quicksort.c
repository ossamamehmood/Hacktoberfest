#include <stdio.h>

int part(int arr[],int p,int r)
{
    int temp;
    int x=arr[r];
    int i=p-1;
    int j;
    for(j=p;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return(i+1);

}
void quicksort(int arr[],int p,int r)
{
    
    if(p<r)
    {
        int q=part(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
     
    }
}
void main()
{
    int n;
   printf("enter the no.of elements:");
   scanf("%d",&n);
   int arr[n];
   printf("enter the elements of array:");
   for(int i=0;i<n;i++)
   {
        scanf("%d",&arr[i]);
   }
   quicksort(arr,0,n-1);
   printf("sorted array is:");
   for(int i=0;i<n;i++)
   {
       printf("%d",arr[i]);
       printf(" ");
   }
}