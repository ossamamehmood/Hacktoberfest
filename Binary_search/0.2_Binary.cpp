#include <iostream>
using namespace std;

// Left occurence
int firstOccurence(int arr[], int n, int key)
{
    int start = 0;
    int last = n - 1;
    int ans = -1;

    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (key == arr[mid])
        {
            ans = mid;

            last = mid - 1;
        }

        else if (key > arr[mid])
        {
            start = mid + 1;
        }

        else
        {
            last = mid - 1;
        }
    }
    return ans;
}
// Right occurence

int lastOccurence(int arr[], int n, int key)
{
    int start = 0;
    int last = n - 1;
    int ans = -1;

    while (start <= last)
    {
        int mid = (start + last) / 2;
        if (key == arr[mid])
        {
            ans = mid;

            start = mid + 1;
        }

        else if (key > arr[mid])
        {
            start = mid + 1;
        }

        else
        {
            last = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the total value " << endl;
    cin >> n;

    int arr[20];
    cout << "Put all values " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key " << endl;
    int key;
    cin >> key;

    cout << "The Leftmost or first occurence is " << firstOccurence(arr, n, key) << endl;
    cout << "The Rightmost or last occurence is " << lastOccurence(arr, n, key) << endl;
}