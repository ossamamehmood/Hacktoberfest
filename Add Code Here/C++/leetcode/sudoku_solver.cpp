class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int ro, int col, char c)
    {
        // col
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return 0;
        }

        // row
        for (int j = 0; j < 9; j++)
        {
            if (board[ro][j] == c)
                return 0;
        }

        // box
        int rstart = (ro / 3) * 3;
        int cstart = (col / 3) * 3;
        for (int i = rstart; i < rstart + 3; i++)
        {
            for (int j = cstart; j < cstart + 3; j++)
            {
                if (board[i][j] == c)
                    return 0;
            }
        }

        return 1;
    }
    bool solve(vector<vector<char>> &board, int ro, int col)
    {
        if (ro == 9)
            return 1;
        if (col == 9)
            return solve(board, ro + 1, 0);
        if (board[ro][col] != '.')
            return solve(board, ro, col + 1);

        for (char c = '1'; c <= '9'; c++)
        {
            if (isSafe(board, ro, col, c))
            {
                board[ro][col] = c;
                if (solve(board, ro, col + 1))
                    return 1;
                board[ro][col] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
        return;
    }
};