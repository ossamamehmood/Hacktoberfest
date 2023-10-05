#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void shellsort(int *arr, int n){
    for(int gap = n/2;gap>=1;gap=gap/2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]>arr[i])
                    break;
                else{
                    swap(&arr[i+gap], &arr[i]);
                }
            }
        }
    }
}

void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}

int main(){
    int *arr, n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);


    display(arr, n);
    shellsort(arr, n);
    display(arr, n);

}
