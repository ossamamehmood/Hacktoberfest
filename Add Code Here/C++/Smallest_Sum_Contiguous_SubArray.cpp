#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int Size;
    cout<<"Enter the Size Of Array : ";
    cin>>Size;
    int *arr = new int [Size];  // Allocate Memory On Heap
    for (int i = 0; i < Size; i++)
    {
        cout<<"Enter The Value at "<<i<< " Index : "<<" ";
        cin>>arr[i];
    }
    int sum = INT_MAX;
    int curSum = 0;
    for (int i = 0; i < Size; i++)
    {
        curSum+=arr[i];
        curSum = min(curSum,arr[i]);
        sum = min(curSum,sum);
    }
    cout<<"Smallest Sum in Contiguous SubArray is : "<<sum;
    delete  [] arr; // delete Memory On Heap
    arr = nullptr;
    
}