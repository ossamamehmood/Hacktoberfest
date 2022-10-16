class Solution
{
    vector<string> ops;

    void solve(vector<vector<int>> m, int n, int i, int j, string op)
    {
        if (i == n - 1 && j == n - 1 && m[i][j] == 1)
        {
            ops.push_back(op);
            return;
        }

        if (m[i][j] == 0)
            return;
        m[i][j] = 0;

        if (i + 1 < n && m[i + 1][j] == 1)
        {
            // down move
            string newOp = op;
            newOp.push_back('D');
            solve(m, n, i + 1, j, newOp);
        }
        if (j - 1 >= 0 && m[i][j - 1] == 1)
        {
            // left move
            string newOp = op;
            newOp.push_back('L');
            solve(m, n, i, j - 1, newOp);
        }
        if (j + 1 < n && m[i][j + 1] == 1)
        {
            // right move
            string newOp = op;
            newOp.push_back('R');
            solve(m, n, i, j + 1, newOp);
        }
        if (i - 1 >= 0 && m[i - 1][j] == 1)
        {
            // up move
            string newOp = op;
            newOp.push_back('U');
            solve(m, n, i - 1, j, newOp);
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string op = "";
        solve(m, n, 0, 0, op);
        return ops;
    }
};
