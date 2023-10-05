#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int strangePrinter(string s)
    {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        return solve(s, 0, n - 1, dp);
    }

private:
    int solve(string &s, int i, int j, vector<vector<int>> &dp)
    {

        if (i > j)
            return 0;

        if (dp[i][j] != 0)
            return dp[i][j];

        int ans = solve(s, i, j - 1, dp) + 1;

        for (int k = i; k < j; k++)
        {
            if (s[k] == s[j])
            {
                ans = min(ans, solve(s, i, k, dp) + solve(s, k + 1, j - 1, dp));
            }
        }

        return dp[i][j] = ans;
    }
};

int main()
{
    // call the fn here
    return 0;
}