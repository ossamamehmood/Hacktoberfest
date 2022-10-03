class Solution
{
    int m, n, dir[5] = {-1, 0, 1, 0, -1};

    int dfs(int x, int y, vector<vector<int>> &g)
    {
        if (x < 0 || y < 0 || x == m || y == n || g[x][y] == 0)
            return 0;

        g[x][y] = 0;
        int ans = 1;

        for (int i = 0; i < 4; ++i)
            ans += dfs(x + dir[i], y + dir[i + 1], g);

        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    res = max(res, dfs(i, j, grid));

        return res;
    }
};