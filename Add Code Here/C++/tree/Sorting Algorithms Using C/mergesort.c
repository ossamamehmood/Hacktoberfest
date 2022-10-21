#include<stdio.h>
#include<conio.h>
void Mergesort(int[],int,int);
void Merge(int[],int ,int,int);
int main()
{
    int arr[50];
    int i,size;
    printf("Enter the size of array");
    scanf("%d",&size);
    printf("Enter the elements");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    Mergesort(arr,0,size-1);
    printf("After Merge Sort");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}
void Mergesort(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        Mergesort(arr,low,mid);
        Mergesort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
void Merge(int arr[],int low,int mid,int high)
{
    int i,j,k,lo,temp[50];
    lo=low;
    i=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            
            temp[lo]=arr[i];
            i++;
        }
        else
        {
            temp[lo]=arr[j];
            j++;
        }
        lo++;
        
    }
    if(i>mid)
    {
        for(k=j;k<=high;k++)
        {
            temp[lo]=arr[k];
            lo++;

        }
    }
    else
    {
        for(k=i;k<=mid;k++)
        {
         temp[lo]=arr[k];
         lo++;  
        }
    }
    for(k=0;k<=high;k++)
        arr[k]=temp[k];
    
}