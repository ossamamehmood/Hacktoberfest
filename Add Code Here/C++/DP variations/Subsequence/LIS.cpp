// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity : O(N2)
// Space Complexity : O(N)

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // initialize with 1 because we can always t5ake curr element
        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            // check LIS upto i and store max
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    //       lena k baad(main dp)    nehi lene k baad
                    dp[i] = max(1 + dp[j], dp[i]);

                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}