#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << "Element at index " << i << " is " << arr.A[i] << endl;
    }
}
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        cout << "Bhar gaya hai bsdk";
        return;
    }
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
bool IsSorted(struct Array arr)
{
    int i = 0;
    for (i = 0; i < (arr.length - 1); i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
             return false;
        }
    }
    return true;
}
void Rearrange(struct Array *arr){
    int i = 0,j = arr->length-1;
    while (i < j)
    {
        /* code */
        while (arr->A[i]<0)
        {
           i++;
        }
        while (arr->A[j]>0)
        {
           j--;
        }
    
        if(i<j){Swap(&arr->A[i], &arr->A[j]);}
    }
    
}
int main()
{
    struct Array arr
    {
        {1, 2, 3, 5, 6, 7, 8, 9}, 10, 8
    };
    struct Array arr1
    {
        {1, 2, -3, 5, -6, 7, -8, -9}, 10, 8
    };
    Display(arr1);
    // InsertSort(&arr, 4);
    // cout << IsSorted(arr);
Rearrange(&arr1);
    Display(arr1);

    return 0;
}