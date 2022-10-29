// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }
        int dp[n + 1];

        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = nums[1];
        for (int i = 3; i <= n; i++)
        {
            // take this test case - [2,1,1,2] , in these cases we need to check (i-3)th posi also since
            // ans for this test case is 4
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
        }

        return max(dp[n], dp[n - 1]);
    }
};

int main()
{
    // Main function goes here
    return 0;
}