#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    // Swap function to swap values
    int temp=*x;
    *x = *y;
    *y = temp;
}
int findMax(int arr[],int n)
{
    // find maximum in array
    int max = INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}
void CountSort(int arr[],int n)
{
    int i,j,max,*auxi;
    max = findMax(arr,n);
    auxi = (int *) malloc (sizeof(int)*(max+1));
    for(i =0;i < max+1;i++)
    {
        auxi[i] = 0;
    }
    for(i =0; i < n; i++)
    {
        auxi[arr[i]]++;
    }
    i =0;
    j =0;
    while(j < max+1)
    {
        if(auxi[j] > 0)
        {
            arr[i++]=j;
            auxi[j]--;
        }else{
            j++;
        }
    }
}
int main()
{
    int n;
    
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter elements in Array : ");
    for(int i =0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    CountSort(arr,n);
 
    for(int i =0; i < n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
    return 0;
}