// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    // LIS variation -> L decreasing S

    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = ages.size();

        vector<int> dp(n, 0);
        // sort as LIS
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});

        int res = INT_MIN;
        sort(v.begin(), v.end());

        // initializaton
        for (int i = 0; i < n; i++)
        {
            dp[i] = v[i].second;
        }

        // calc max score upto ith pos
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                // if senior(i) score is more than equal to junior{j} score then max
                if (v[i].second >= v[j].second)
                    dp[i] = max(dp[i], dp[j] + v[i].second);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main()
{
    // Main function goes here
    return 0;
}