// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxi = 0;

        for (int i = 2; i < n; i++)
        {
            int l = 0, r = i - 1;

            // two sum -> map also can be used here
            while (l < r)
            {
                int sum = a[l] + a[r];
                if (sum > a[i])
                    r--;
                else if (sum < a[i])
                    l++;
                else
                {
                    // target sum obtained using l & r
                    dp[r][i] = dp[l][r] + 1;
                    maxi = max(maxi, dp[r][i]);
                    l++;
                    r--;
                }
            }
        }

        return maxi == 0 ? 0 : maxi + 2;
    }
};

int main()
{
    // Main function goes here
    return 0;
}