//Shibam Debnath
//June ,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int round_rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n + 1];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            // here no need to check (i-3)th case 
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        // Since you cannot rob both the first and last house, just create two separate vectors, one excluding the first house, and another excluding the last house. The 
        //best solution generated from these two vectors using the original House Robber DP algorithm is the optimal one.

        vector<int> a(nums.begin() + 1, nums.end());
        vector<int> b(nums.begin(), nums.end() - 1);

        int ans = max(round_rob(a), round_rob(b));

        return ans;
    }
};

int main() {
    //Main function goes here
    return 0;
}