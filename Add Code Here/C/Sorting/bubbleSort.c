#include <stdio.h>

void show(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
      printf(" %d ",arr[i]);
    }

    printf("\n");
}

int main()
{

    int arr[] = {1, 12, 23, 111134, 45, 56, 67, 78, 89, 910};

    printf("array before sorting : ");
    show(arr);
    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[j]>arr[j+1])
            {
               temp = arr[j+1];
               arr[j+1]=arr[j];
               arr[j]=temp;
            }
            
        }
        
    }
   printf("array after sorting : ");
    show(arr);
}