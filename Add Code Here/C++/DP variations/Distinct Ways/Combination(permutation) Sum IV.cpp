// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int helper(vector<int> &nums, int target, vector<int> &dp, int n)
    {

        if (target == 0)
            return 1;

        if (dp[target] != -1)
            return dp[target];

        // logic
        dp[target] = 0;

        for (auto &num : nums)
        {
            if (num <= target)
            {
                dp[target] += helper(nums, target - num, dp, n);
            }
        }
        return dp[target];
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return helper(nums, target, dp, n);
    }
};

int main()
{
    // Main function goes here
    return 0;
}