/* Insert an element from unsorted array to its correct position in sorted array */
/* INSERTION SORT */

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the Array : " << endl;
    for (int k = 0; k < n; k++)
    {
        cin >> arr[k];
    }
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i -1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    cout << "Elements of Array after sorting are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
