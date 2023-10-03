//Link: https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:

    int dp[201][201];

    int f(int i, int j, vector<vector<int>>& grid){
        if(i == grid.size() - 1 and j == grid[0].size() - 1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(i + 1 < grid.size()) ans = min(ans, grid[i][j] + f(i + 1, j, grid));
        if(j + 1 < grid[0].size()) ans = min(ans, grid[i][j] + f(i, j + 1, grid));
        return dp[i][j] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, grid);
    }
};
