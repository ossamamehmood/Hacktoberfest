class Solution
{
    int dir[5] = {-1, 0, 1, 0, -1};
    int m, n;

    void dfs(int x, int y, vector<vector<char>> &g)
    {
        if (x < 0 || x == m || y < 0 || y == n || g[x][y] == '0')
            return;

        g[x][y] = '0';
        for (int i = 0; i < 4; ++i)
            dfs(x + dir[i], y + dir[i + 1], g);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1')
                    res++, dfs(i, j, grid);

        return res;
    }
};