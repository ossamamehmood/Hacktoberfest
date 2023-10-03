//Link: https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public:
    int cost(int n, vector <int>& dp){
        if(n <= 1)  return 1;
        if(dp[n] != -1) return dp[n];
        int incl = cost(n - 2, dp);
        int excl = cost(n - 1, dp);
        dp[n] = incl + excl;
        return dp[n];
    }
    int climbStairs(int n) {
        vector <int> dp(n + 1, -1);
        return cost(n, dp);
    }
};
