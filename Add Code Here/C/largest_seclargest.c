#include <stdio.h>
int main()
{
    int arr[100], i, n, largest, sec_largest;
    printf("Enter the size of an Array : \n");
    scanf("%d", &n);
    printf("Enter the elements of an Array : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    sec_largest = arr[1];
    for (i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sec_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > sec_largest && arr[i] != largest)
        {
            sec_largest = arr[i];
        }
    }
    printf("Largest is = %d \nSecond Largest is = %d", largest, sec_largest);
    return 0;
}