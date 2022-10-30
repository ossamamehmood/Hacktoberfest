// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<int>> dp;

    int MCM(int arr[], int i, int j)
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

        int mini = INT_MAX;

        // recursive call where we move k from i ton j-1

        for (int k = i; k <= j - 1; k++)
        {
            int cost = arr[i - 1] * arr[k] * arr[j];
            int temp_ans = MCM(arr, i, k) + MCM(arr, k + 1, j) + cost;

            mini = min(mini, temp_ans);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // initialisation with -1
        dp.resize(N, vector<int>(N, -1));
        // we shouls start from 1 since i th matrix has the dimensions (arr[i-1] x arr[i]).
        // for i=0 we wouldn't get arr[i-1] i.e. row size
        return MCM(arr, 1, N - 1);
    }
};

int main()
{
    // Main function goes here
    return 0;
}