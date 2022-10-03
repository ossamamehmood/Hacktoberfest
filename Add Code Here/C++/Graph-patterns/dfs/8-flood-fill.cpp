// DFS Solution
class Solution
{
    int m, n;
    int dir[5] = {-1, 0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<int>> &img, int &new_col, int &og_col)
    {
        if (x < 0 || y < 0 || x == m || y == n || img[x][y] != og_col)
            return;

        img[x][y] = new_col;
        for (int i = 0; i < 4; ++i)
            dfs(x + dir[i], y + dir[i + 1], img, new_col, og_col);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc])
            return image;

        m = image.size();
        n = image[0].size();
        int col = image[sr][sc];

        dfs(sr, sc, image, newColor, col);
        return image;
    }
};

// BFS SOLUTION
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc])
            return image;

        int m = image.size(), n = image[0].size();

        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        int col = image[sr][sc];
        int dir[5] = {-1, 0, 1, 0, -1};

        while (q.size())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            image[x][y] = newColor;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (nx < 0 || nx == m || ny < 0 || ny == n || image[nx][ny] != col)
                    continue;

                q.emplace(nx, ny);
            }
        }

        return image;
    }
};