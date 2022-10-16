#include<iostream>

using namespace std;

// Count Sort Function //
void cSort(int arr[] , int sorted[] , int n)
{
    int max = 0;
    for(int i=0 ; i<n ; i++)
    {
        max = std::max(max , arr[i]);
    }

    int count[max + 1] = { 0 };
    for(int i=0 ; i<n ; i++)
    {
        count[arr[i]]++;
    }

    for(int i=1 ; i<=max ; i++)
    {
        count[i] += count[i-1];
    }

    for(int i=n-1 ; i>=0 ; i--)
    {
        count[arr[i]]--;
        sorted[count[arr[i]]] = arr[i];
    }
}

// Driver Function //
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n] , sorted[n];
    cout<<"Enter the array elements:\n";
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    cSort(arr , sorted , n);
    
    for(int i=0 ; i<n ; i++)
    {
        cout<<sorted[i];
    }
    return 0;
}
