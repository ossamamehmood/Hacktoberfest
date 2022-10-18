#include <stdio.h>
void show(int arr[]){for (int i = 0; i < 10; i++)
{
    printf(" %d ",arr[i]);
}
}
void main(){

    int arr[10]={23,43,37,5,55,5,3,54,3,543};
    printf("before sorting elements in array are  ");
    show(arr);
    int key,j;

    for (int  i = 1; i < 10; i++)
    {   key=arr[i];
        j=i-1;
        while (j>=0 && key<arr[j])
        {
           arr[j+1]=arr[j];
           j--;
        }
        arr[j+1]=key;
        
        
    }
    printf("before sorting elements in array are  ");

    show(arr);
}