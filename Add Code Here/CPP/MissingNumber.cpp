// Find the missingNumber in the array of n distinct integers containing [0,n].
// solved in 2 methods
#include <bits/stdc++.h>
using namespace std;

int missingNumber1(vector<int> &arr)
{
    int n = arr.size();
    int ans = n;
    // using the fact (x^x = 0)
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ i;
        ans = ans ^ arr[i];
    }
    return ans;
}

int missingNumber2(vector<int> &arr)
{
    int n = arr.size();
    int ans = n * (n + 1) / 2; // sum of first n numbers
    for (int i = 0; i < n; i++)
    {
        ans -= arr[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = missingNumber1(arr);
    cout << ans << endl;
}