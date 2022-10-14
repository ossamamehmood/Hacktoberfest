#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void shellSort(int arr[],int n)
{
    int gap,i,j,temp;

    for(gap = n/2; gap >= 1; gap/=2)
    {
        for(i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i-gap;
            while(j >=0 && arr[j] > temp)
            {
                arr[j+gap] = arr[j];
                j = j-gap;
            }
            arr[j+gap] = temp;
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
    
    shellSort(arr, n);
    
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
 
    return 0;
}