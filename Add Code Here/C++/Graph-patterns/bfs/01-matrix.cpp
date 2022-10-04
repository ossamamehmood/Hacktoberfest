// 2 Methods
// 1. MODIFIED BFS
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), d[] = {-1, 0, 1, 0, -1};
        queue<int> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0)
                    q.push(n * i + j);
                else
                    mat[i][j] = INT_MAX;

        while (q.size())
        {
            int y = q.front() % n, x = (q.front() - y) / n;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + d[i], ny = y + d[i + 1];

                if (nx < 0 || ny < 0 || nx == m || ny == n)
                    continue;

                if (mat[x][y] + 1 < mat[nx][ny])
                    mat[nx][ny] = 1 + mat[x][y], q.push(nx * n + ny);
            }
        }

        return mat;
    }
};

// 2. DP
/*
    ########################################
    GENERAL IDEA
    
    at each i, j we have to compare it with 4 positions,
    
    1) top i - 1, j    ---|
                          | can we done using top left to bottom right traversal  
    2) left i, j - 1   ---|
    
    3) right i, j + 1  ---|
                          | can we done using bottom right to top left traveral
    4) bottom i + 1, j ---|
    
    ########################################

    let dp[i][j] = min distance from 0 to i, j position
    
    first we traverse from top left to bottom right
    at each i, j
    
    we have, dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1
    [as i-1,j and i,j-1 are already optimised in this manner]
    
    now, we traverse from bottom right to top left
    at each i, j

    we have dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1]) + 1)
    [as i+1,j and i,j+1 are already optimised in this manner]

*/
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), t, b, l, r, MAX = 1e5;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j])
                {
                    t = i == 0 ? MAX : mat[i - 1][j];
                    l = j == 0 ? MAX : mat[i][j - 1];

                    mat[i][j] = min(l, t) + 1;
                }

        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                if (mat[i][j])
                {
                    b = i == m - 1 ? MAX : mat[i + 1][j];
                    r = j == n - 1 ? MAX : mat[i][j + 1];

                    mat[i][j] = min(mat[i][j], min(b, r) + 1);
                }

        return mat;
    }
};