class Solution
{
    int dir[5] = {-1, 0, 1, 0, -1};
    int m, n;

    void dfs(int i, int j, vector<vector<char>> &board)
    {
        board[i][j] = '1';

        for (int x = 0; x < 4; ++x)
        {
            int nx = i + dir[x], ny = j + dir[x + 1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] != 'O')
                continue;

            dfs(nx, ny, board);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();

        // left and right border
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board);
        }

        // top and bottom
        for (int i = 0; i < n; ++i)
        {
            if (board[0][i] == 'O')
                dfs(0, i, board);
            if (board[m - 1][i] == 'O')
                dfs(m - 1, i, board);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                board[i][j] = board[i][j] == '1' ? 'O' : 'X';
            }
        }
    }
};