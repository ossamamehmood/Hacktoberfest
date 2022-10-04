class Solution
{
    void dfs(int i, int j, int m, int n, vector<vector<char>> &grid)
    {
        if (i < 0 || i == m || j < 0 || j == n)
            return;
        if (grid[i][j] == '0' || grid[i][j] == '2')
            return;

        grid[i][j] = '2';
        dfs(i - 1, j, m, n, grid);
        dfs(i, j - 1, m, n, grid);
        dfs(i + 1, j, m, n, grid);
        dfs(i, j + 1, m, n, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, m, n, grid);
                }

        return count;
    }
};