#include <iostream> //This programs only works when array is sorted in
// increasing order ex.11 22 33 44 55 else wont work
using namespace std;
int binarysearch(int ar[], int m, int n)
{
    int s = 0; // starting pointer at 0
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ar[mid] == m)
        {
            return mid;
        }
        else if (ar[mid] > m)
        {
            e = mid - 1;
        }
        else if (ar[mid] < m)
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int m;
    cout << "element to be searched----";
    cin >> m;
    cout << binarysearch(ar, m, n);
    return 0;
}
