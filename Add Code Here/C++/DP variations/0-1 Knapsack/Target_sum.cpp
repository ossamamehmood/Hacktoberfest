// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int subset_sum(vector<int> &arr, int t)
    {
        int n = arr.size();

        // Dp matrix
        int ans[n + 1][t + 1];

        // *Base Case or initialization

        for (int i = 1; i <= t; i++) ans[0][i] = 0;
        for (int i = 0; i <= n; i++) ans[i][0] = 1;


        //* Choice Diagram

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                if (arr[i - 1] <= j)
                {
                    ans[i][j] = ans[i - 1][j - arr[i - 1]] + ans[i - 1][j];
                }
                else
                {
                    ans[i][j] = ans[i - 1][j];
                }
            }
        }
        return ans[n][t];
    }

    int findTargetSumWays(vector<int> &arr, int diff)
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        int t = (diff + sum) / 2;

        if (n == 0 || t > sum || (diff + sum) % 2 != 0)
            return 0;

        t = abs(t);

        return subset_sum(arr, t);
    }
};

int main()
{
    // Main function goes here
    return 0;
}

