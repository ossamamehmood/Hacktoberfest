#include <iostream>
using namespace std;
struct Array
{
    /* data */
    int A[10];
    int size;
    int length;
};
int BinarySearch(struct Array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
    mid = (l + h) / 2;
        /* code */
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
            {
                l = mid + 1;
            }
    }
    return -1;
}
int BSearch(int a[],int l, int h, int key){
    int mid;
    static int c;
    cout<< c<<endl;
    c++;
    if(l<=h){
    mid = (l+h)/2;
    if(key == a[mid]){
        return mid;
    }
    else if(key < a[mid]){
       return BSearch(a, l, mid-1,key);
    }
    else{
        return BSearch(a, mid +1, h,key);
    }
    }
    return -1;
}
int main()
{
    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 7, 8}, 10, 8};
    cout<< BinarySearch(arr1, 5)<< endl;
    cout<< BSearch(arr1.A, 0, arr1.length-1,4);
    return 0;
}