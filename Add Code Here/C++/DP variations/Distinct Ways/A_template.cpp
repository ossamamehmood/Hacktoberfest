// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int target = 8;
vector<int> ways, dp;

int helper()
{
    //        T E M P L A T E

    for (int i = 1; i <= target; ++i)
    {
        for (int j = 0; j < ways.size(); ++j)
        {
            if (ways[j] <= i)
            {
                dp[i] += dp[i - ways[j]];
            }
        }
    }

    return dp[target];
}

int main()
{
    // Main function goes here
    return 0;
}