// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // first row will be same

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // store min of all three possibilities

                // TRICK -  since j-1 can be out of range so  matrix[i-1][j-1] = matrix[i-1][max(0,j-1)]
                matrix[i][j] = matrix[i][j] + min(matrix[i - 1][j], min(matrix[i - 1][max(0, j - 1)], matrix[i - 1][min(j + 1, n - 1)]));
            }
        }

        int ans = *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}


