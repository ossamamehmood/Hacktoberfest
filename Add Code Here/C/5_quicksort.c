#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb, end = ub;

    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;

        while (arr[end] > pivot)
            end--;

        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[end], &arr[lb]);
    return end;
}

void quicksort(int *arr, int lb, int ub)
{

    if (lb < ub)
    {
        int mid = partition(arr, lb, ub);
        quicksort(arr, lb, mid - 1);
        quicksort(arr, mid + 1, ub);
    }
}

void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}

int main()
{

    int *arr, n, i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    printf("Enter elements of array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    display(arr, n);
    quicksort(arr, 0, n);
    display(arr, n);
}