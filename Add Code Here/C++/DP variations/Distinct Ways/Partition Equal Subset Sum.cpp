// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool subset_sum(vector<int> &arr, int n, int t)
    {
        // Dp matrix
        bool ans[n + 1][t + 1];

        // *Base Case or initialization

        for (int i = 1; i <= t; i++)
            ans[0][i] = false;

        for (int i = 0; i <= n; i++)
            ans[i][0] = true;

        // Choice Diagram

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= t; j++)
            {
                if (arr[i - 1] <= j)
                    ans[i][j] = ans[i - 1][j - arr[i - 1]] || ans[i - 1][j];
                else
                    ans[i][j] = ans[i - 1][j];
            }
        }
        return ans[n][t];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        if (subset_sum(nums, n, target))
            return true;
        return false;
    }
};

int main()
{
    // Main function goes here
    return 0;
}