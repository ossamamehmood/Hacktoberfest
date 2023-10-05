#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionsort(int *arr, int n){

    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        int min=i;
        for ( j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
            swap(&arr[i], &arr[min]);
        
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}

int main()
{

int *arr,n,i;
printf("Enter number of elements in array: ");
scanf("%d", &n);

arr=(int *)malloc(sizeof(int)*n);

printf("Enter elements of array: ");
for(i=0;i<n;i++)
    scanf("%d", &arr[i]);

display(arr,n);
selectionsort(arr,n);
display(arr,n);


return 0;
}