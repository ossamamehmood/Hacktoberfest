#include <iostream>
using namespace std;

int firPivot(int arr[], int n)
{
    int start = 0;
    int last = n - 1;
    while (start < last)
    {
        int mid = start + (last - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            last = mid;
        }
    }
    return start;
}

int secSearch(int arr[], int s, int l, int key)
{
    int start = s;
    int last = l;

    while (start <= last)
    {
        int mid = start + (last - start) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            last = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the total value " << endl;
    cin >> n;

    int arr[10];
    cout << "Put the value " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key " << endl;
    int key;
    cin >> key;

    int pivot =  firPivot(arr, n);

    if (key >= arr[pivot] && key <= arr[n-1])
    {
        cout << "The final index is (lower part) " << secSearch(arr,pivot, n-1, key) << endl;
    }
    else{
        cout << "The final index is (upper part) " << secSearch(arr,0, pivot -1, key) << endl;

    }
    
}