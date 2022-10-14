// CPP program to count frequencies of array elements
#include <bits/stdc++.h>
using namespace std;
 
void countFreq(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto x : mp)
        cout <<"The frequency of "<< x.first << " is " << x.second << endl;
}
 
int main()
{
    int k;
    cout<<"Enter the size of array: ";
    cin>>k;
    int arr[k];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<k;i++){
            cin>>arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}
