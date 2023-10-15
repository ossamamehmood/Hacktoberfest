#include <iostream>
using namespace std;

int main()
{
    int A[10] = {1, 5, 8, 9, 12, 16, 18, 24, 28, 36}, key, l = 0, h = 9, mid;
    cout << "Enter Key: ";
    cin >> key;
    while (l < h)
    {
        mid = (l + h) / 2;
        if (A[mid] == key)
        {
            cout << "Found at " << mid << endl;
            return 0;
        }
        else if(A[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << "Not found";
}