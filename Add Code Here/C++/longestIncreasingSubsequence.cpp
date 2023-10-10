#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longestIncSubSeq(vector<int>& arr, vector<int>& dp) {
    int n = arr.size();
    int maxi = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n, 1);
    cout << longestIncSubSeq(arr, dp);
    return 0;
}