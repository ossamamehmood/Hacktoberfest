// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int Subset_sum_target = (target + sum) / 2;

        if (Subset_sum_target > sum || (target + sum) % 2 != 0)
            return 0;

        Subset_sum_target = abs(Subset_sum_target);

        return subset_sum(nums, Subset_sum_target);
    }

    int subset_sum(vector<int> &nums, int t)
    {
        int n = nums.size();

        // Dp matrix
        int dp[n + 1][t + 1];

        for (int i = 0; i <= t; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][t];
    }
};

int main()
{
    // Main function goes here
    return 0;
}