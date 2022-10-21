/*You are given an array prices where prices[i] is the price
of a given stock on the ith day.
Find the maximum profit you can achieve.
You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &prices, int idx, int flag, int tx, vector<vector<vector<int>>> &dp, int k)
    {

        if (idx == prices.size())
            return 0;
        if (tx == 2)
            return 0;

        if (dp[idx][flag][tx] != -1)
            return dp[idx][flag][tx];

        // flag ==0
        if (flag == 0)
        {
            // case 1 : buy
            int x = -prices[idx] + solve(prices, idx + 1, 1, tx, dp, k);
            // case 2 : no buy
            int y = solve(prices, idx + 1, 0, tx, dp, k);

            return dp[idx][flag][tx] = max(x, y);
        }

        // flag ==1
        else
        {
            // case 1 : sell
            int x = prices[idx] + solve(prices, idx + 1, 0, tx + 1, dp, k);
            // case 2 : no sell
            int y = solve(prices, idx + 1, 1, tx, dp, k);

            return dp[idx][flag][tx] = max(x, y);
        }
    }
    int maxProfit(vector<int> &prices)
    {

        int tx = 0;
        int flag = 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(prices, 0, flag, tx, dp, 2);
    }
};

int main()
{
    vector<int> arr = {3,3,5,0,0,3,1,4};
    Solution obj;
    cout << obj.maxProfit(arr);

    return 0;
}
