#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,min_ele,max_ele;
    cout << "Enter the length of array" << endl;
    cin >> n; // Taking array length as input
    vector<int> arr(n);
    cout << "Enter array elements" << endl;
    for(i=0;i<n;i++) // Loop to take array elements as input
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end()); // Sorting array elements
    min_ele=arr[0]; // first element obtained after sorting is the min_ele
    max_ele=arr[n-1]; // last element obtained after sorting is the max_ele
    cout << "Minimum element is " << min_ele << endl;
    cout << "Maximum element is " << max_ele << endl;
    return 0;
}
