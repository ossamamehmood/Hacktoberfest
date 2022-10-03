// BFS
// converting 2d to 1d
// r,c =====> r * n + c
// where n = number of cols
class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r, int c, int color)
    {
        int m = grid.size(), n = grid[0].size(), dir[5] = {-1, 0, 1, 0, -1}, og = grid[r][c];
        unordered_set<int> vis;

        queue<int> q;
        q.push(r * n + c);
        vis.insert(r * n + c);

        while (q.size())
        {
            int v = q.front();
            q.pop();
            int y = v % n, x = (v - y) / n;

            if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                grid[x][y] = color;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i], ny = y + dir[i + 1];

                if (nx < 0 || ny < 0 || nx == m || ny == n || vis.find(n * nx + ny) != vis.end())
                    continue;

                if (grid[nx][ny] == og)
                    q.push(n * nx + ny), vis.insert(n * nx + ny);
                else
                    grid[x][y] = color;
            }
        }

        return grid;
    }
};

// DFS
// CONCEPT -> negate all valid values so as to not visit them again
// un-negate all values who have 4 valid neighbours
class Solution
{
    int m, n, dir[5] = {-1, 0, 1, 0, -1};

    void dfs(int x, int y, int og, vector<vector<int>> &grid)
    {
        grid[x][y] = -og;
        int cnt = 0; // valid neighbours

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i], ny = y + dir[i + 1];

            if (nx < 0 || ny < 0 || nx == m || ny == n || abs(grid[nx][ny]) != og)
                continue;

            ++cnt;

            if (grid[nx][ny] == og)
                dfs(nx, ny, og, grid);
        }

        if (cnt == 4)
            grid[x][y] = og;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
    {
        m = grid.size();
        n = grid[0].size();

        int og = grid[r0][c0];
        if (og == color)
            return grid;

        dfs(r0, c0, og, grid);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = grid[i][j] == -og ? color : grid[i][j];

        return grid;
    }
};