#include <iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}
void Reverse(struct Array *arr)
{

    int *B;
    int i;
    int j;
    B = (int *)malloc(arr->length * sizeof(int));

    for (j = arr->length - 1, i = 0; j >= 0; i++, j--)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}
void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = arr->length - 1, j = 0; j < i; j++, i--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}
int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 20, 10};
    Reverse2(&arr);
    Display(arr);
    return 0;
}