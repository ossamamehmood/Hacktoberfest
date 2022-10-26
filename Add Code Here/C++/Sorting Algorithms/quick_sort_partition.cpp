#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
5
4 5 3 7 2
Sample Output
4 is pivot
after sort:
2 3 [4] 5 7
3 2 4 5 7
How?
5 3 7 [4] 2
2 3 [4] 5 7
3 2 4 5 7
*/

int arr[1005];

int partition(int v[], int low, int high)
{
    int pivot = v[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);

    return (i + 1);
}

void quickSort(int v[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

void printArray(int v[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
        cout << v[i] << " ";
    cout << endl;
}

int main(void)
{
    // vector <int>  vec;
    int sz;
    cin >> sz;

    for (int i = 0; i < sz; ++i)
    {
        //        int tmp;
        cin >> arr[i];
        //        vec.push_back(tmp);
    }

    quickSort(arr, 0, sz - 1);
    printArray(arr, sz);

    return 0;
}