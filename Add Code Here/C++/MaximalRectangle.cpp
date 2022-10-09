// 85. Leetcode {HARD} [DP , Arrays , Stack]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        if (matrix.size() == 0)
            return 0;

        int ans = 0;
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // columns

        vector<int> height(n, 0); // height

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    height[j] = 0;
                    continue;
                }
                height[j]++;
                for (int cur = j - 1, pre = height[j]; cur >= 0; cur--)
                {
                    if (height[cur] == 0)
                        break;
                    pre = min(pre, height[cur]);
                    ans = max(ans, (j - cur + 1) * pre);
                }
                ans = max(ans, height[j]);
            }
        }
        return ans;
    }
};