#include <stdio.h>
#include <stdbool.h>
void set_union(int *arr1, int *arr2, int a, int b)
{
    int arr[100], cnt = 0;
    bool check;
    for (int i = 0; i < a; i++)
    {
        check = true;
        for (int j = 0; j < cnt; j++)
            if (arr[j] == arr1[i])
                check = false;
        if (check)
        {
            arr[cnt] = arr1[i];
            cnt++;
        }
    }
    for (int i = 0; i < b; i++)
    {
        check = true;
        for (int j = 0; j < cnt; j++)
            if (arr[j] == arr2[i])
                check = false;
        if (check)
        {
            arr[cnt] = arr2[i];
            cnt++;
        }
    }
    printf("\nThe union of the sets is : ");
    for (int i = 0; i < cnt; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int A[100], B[100], x, y;
    printf("Enter the size of set A : ");
    scanf("%d", &x);
    printf("Enter the elements of A : ");
    for (int i = 0; i < x; i++)
        scanf("%d", &A[i]);
    printf("Enter the size of set B : ");
    scanf("%d", &y);
    printf("Enter the elements of B : ");
    for (int i = 0; i < y; i++)
        scanf("%d", &B[i]);
    set_union(A, B, x, y);
}

// Code written by _100rabh_