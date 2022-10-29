// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &A)
    {

        if (A[0][0] == 1)
            return 0;
        int m = A.size();
        int n = A[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j] == 1 || (i == 0 && j == 0))
                    continue;
                else
                    dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
        return dp[m - 1][n - 1];
    }
};

int main()
{
    // Main function goes here
    return 0;
}