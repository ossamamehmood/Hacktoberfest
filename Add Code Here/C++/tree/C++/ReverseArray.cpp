#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << ("Enter Size of Array ");
    cin >> n;

    cout << ("Enter Elements ");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << ("The Array After Reversing is ");

    for (int j = n-1 ; j >= 0; j--)
    {
        cout << arr[j]<<" ";
    }

    return 0;
}
