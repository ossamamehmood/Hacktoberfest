#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}

void countsort(int *a, int n, int k)
{

    int b[n];
    int count[k + 1];
    for (int i = 0; i <=k; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        ++count[a[i]];

    for (int i = 1; i <= k; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        b[--count[a[i]]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = b[i];
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

    int k = getMax(arr, n);

    display(arr, n);
    countsort(arr, n, k);
    display(arr, n);
}