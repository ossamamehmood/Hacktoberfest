// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    // pepcoding

    int maximalSquare(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int res = 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = n - 1; i >= 0; i--)
            dp[i][m - 1] = mat[i][m - 1] - '0';

        for (int i = m - 1; i >= 0; i--)
            dp[n - 1][i] = mat[n - 1][i] - '0';

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {

                if (mat[i][j] == '1')
                {
                    // take min all all three directions bottom , bottom right and right
                    int mn = min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
                    dp[i][j] = mn + 1;
                }
                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};

int main()
{
    // Main function goes here
    return 0;
}