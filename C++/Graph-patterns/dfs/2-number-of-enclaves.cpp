class Solution
{
    int dir[5] = {-1, 0, 1, 0, -1};
    int m, n;

    void dfs(int x, int y, vector<vector<int>> &grid)
    {
        grid[x][y] = 0;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i], ny = y + dir[i + 1];

            if (nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] == 0)
                continue;

            dfs(nx, ny, grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        // left and right border
        for (int i = 0; i < m; ++i)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);
            if (grid[i][n - 1] == 1)
                dfs(i, n - 1, grid);
        }

        // top and bottom border
        for (int i = 0; i < n; ++i)
        {
            if (grid[0][i] == 1)
                dfs(0, i, grid);
            if (grid[m - 1][i] == 1)
                dfs(m - 1, i, grid);
        }

        int total_ones = 0;

        for (int i = 0; i < m; ++i)
            total_ones += accumulate(grid[i].begin(), grid[i].end(), 0);

        return total_ones;
    }
};