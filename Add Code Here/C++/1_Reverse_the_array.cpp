#include <bits/stdc++.h> 
using namespace std;

int *reverse(int arr[], int n)
{
    int t;
    for(int i = (n-1); i>(n-1)/2; i--)
    {
        int num = (n-1) - i;
        t = arr[i];
        arr[i] = arr[num];
        arr[num] = t;
    }
    return arr;
}
void printArr (int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main()
{
    
    int t, n;
    cin>>t;
    while(t--)
    {
        cout<<"enter the size of the array"<<endl;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++)
        {
            cin>>arr[i];
        }
        printArr(arr,n);
        reverse(arr,n);
        printArr(arr,n);
    }
    return 0;
}

// Iterative way:
// Time complexity : O(n)