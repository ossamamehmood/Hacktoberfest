#include <iostream>
using namespace std;

int binary(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Your index is " << endl;

            return mid;
        }

        else if (key < arr[mid])
        {
            end = mid - 1;
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

    int arr[100];
    cout << "Put the values " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter key element " << endl;
    int key;
    cin >> key;

    // function calling
    cout << binary(arr, n, key) << endl;
}
