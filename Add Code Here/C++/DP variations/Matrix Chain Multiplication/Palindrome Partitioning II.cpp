// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<int>> dp;

    int minCut(string s)
    {
        int N = s.size();
        // initialisation with -1
        dp.resize(N + 1, vector<int>(N + 1, -1));

        return MCM(s, 0, N - 1);
    }

    int MCM(string &s, int i, int j)
    {
        // base case
        if (i >= j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // ! new addition
        if (palindrome(s, i, j))
        {
            return 0; // since no need to partition
        }

        int mini = INT_MAX;

        int left = 0, right = 0;

        // recursive call where we move k from i ton j-1
        for (int k = i; k < j; k++)
        {
            // This method is giving us tle so we need to further optimise
            // int temp_ans = MCM(s, i, k) + MCM(s, k + 1, j) + 1;

            if (palindrome(s, i, k))
            {
                // check the right side if and only if left is a palindrome else return 0
                right = MCM(s, k + 1, j);
            }
            else
            {
                dp[i][k] = 0;
                continue;
            }

            int temp_ans = right + 1;

            mini = min(mini, temp_ans);
        }

        return dp[i][j] = mini;
    }

    bool palindrome(string &s, int i, int j)
    {
        if (i == j)
            return true;
        if (i > j)
            return true;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}