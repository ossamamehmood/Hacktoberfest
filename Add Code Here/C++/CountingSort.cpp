#include <bits/stdc++.h>
using namespace std;

// counting sort with negative values
void countSort(vector<int> &arr)
{
    // size of the array
    int size = arr.size();

    // finding the range in which value of array element lie, using STL functions
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    // vector to store the frequency of each element in range
    vector<int> countStore(range);

    // iterating through the array and storing the frequency
    for (int i = 0; i < size; i++)
    {
        countStore[arr[i] - min]++;
    }

    // index will keep track of the current position in the array
    int index = 0;

    // for loop to generate the sorted array
    for (int i = 0; i < range; i++)
    {
        while (countStore[i]--)
        {
            arr[index] = i + min;
            // min must be added back
            index++;
        }
    }
}

void countSortMap(vector<int> &arr)
{
    // map to store the frequency
    map<int, int> mp;

    int size = arr.size();

    // for loop to store frequency of array elements in map
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }

    // index keep track of the current position in the array
    int index = 0;

    // for loop to make the array sorted
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        while (i->second)
        {
            arr[index] = i->first;
            index++;
            i->second = i->second - 1;
        }
    }
}

void printArray(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
}

int main()
{
//   driver code
    vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
    countSort(arr);
    printArray(arr);
    countSortMap(arr);
    printArray(arr);
}
