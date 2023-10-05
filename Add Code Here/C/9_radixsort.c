#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int getMax(int *arr, int n)
{
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > k)
            k = arr[i];
    }
    return k;
}

void countsort(int *a, int n, int max, int pos)
{

    int b[n];
    int count[max + 1];
    for (int i = 0; i <=max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        ++count[(a[i]/pos)%10];

    for (int i = 1; i <= max; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[(a[i]/pos)%10]] = a[i];
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

void radixsort(int *arr, int n, int max){

    int pos;
    for(pos=1;(max/pos)>0;pos*=10){
        countsort(arr,n,max,pos);
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

    int max = getMax(arr,n);
    display(arr, n);
    radixsort(arr,n,max);
    display(arr, n);

}
