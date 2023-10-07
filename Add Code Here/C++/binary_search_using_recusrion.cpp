#include <iostream>
using namespace std;
int binarySearch(int A[], int start, int end, int key)
{
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(A[mid] == key)
        {
            return mid;
        }
        else if(A[mid] > key)
        {
            return binarySearch(A, start, mid - 1, key);
        }
        else
        {
         return binarySearch(A, mid + 1, end, key);
        }
    }
    return -1;
}
int main()
{
    int A[] = { 11, 22, 33, 44, 55, 66, 77};
    int n = sizeof(A) / sizeof(A[0]);  //n is the size of the array
    int key;
    cout << "Array Elements :--> ";
    for(int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << "\nEnter Key Element to Search :--> ";
    cin >> key;
    int result = binarySearch(A, 0, n - 1, key);
    if(result == -1)
    {
      cout << "\nElement is not present in array";
    }
    else
    {
     cout << "\nElement is present at index " << result;
    }
    return 0;
}
