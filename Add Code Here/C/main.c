#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selectSort(int *arr, size_t n, int (*cmp)(int, int))
{
    for (size_t i = 0; i < n; ++i)
    {
        size_t min = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (cmp(arr[j], arr[min]) < 0)
            {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int cmp(int a, int b)
{
    return a - b;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    int *arr = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < 10; ++i)
    {
        printf("%d%c", arr[i], i == 9 ? '\n' : ' ');
    }
    selectSort(arr, 10, cmp);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d%c", arr[i], i == 9 ? '\n' : ' ');
    }
    return 0;
}
