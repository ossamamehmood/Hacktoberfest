class Solution
{
    int m, n;

    void dfs(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == 1)
            return;

        grid[x][y] = 1;
        dfs(x - 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x + 1, y, grid);
        dfs(x, y - 1, grid);
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            dfs(i, 0, grid);
            dfs(i, n - 1, grid);
        }

        for (int i = 0; i < n; ++i)
        {
            dfs(0, i, grid);
            dfs(m - 1, i, grid);
        }

        int cnt = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ++cnt;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};