// Shortest Path Using BFS
// Beautiful

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size();
        if (g[0][0] != 0 || g[m - 1][n - 1] != 0)
            return -1;

        int d1[5] = {-1, 0, 1, 0, -1}, d2[6] = {-1, 1, -1, 1, 1, -1};
        queue<int> q;
        q.push(0);

        int steps = 0;

        while (q.size())
        {
            int sz = q.size();
            ++steps;

            while (sz--)
            {
                int y = q.front() % n, x = (q.front() - y) / n;
                q.pop();

                if (x == m - 1 && y == n - 1)
                    return steps;

                for (int i = 0; i < 4; ++i)
                {
                    int x1 = x + d1[i], y1 = y + d1[i + 1], x2 = x + d2[i], y2 = y + d2[i + 2];

                    if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && g[x1][y1] == 0)
                    {
                        g[x1][y1] = 1;
                        q.push(n * x1 + y1);
                    }

                    if (x2 >= 0 && y2 >= 0 && x2 < m && y2 < n && g[x2][y2] == 0)
                    {
                        g[x2][y2] = 1;
                        q.push(n * x2 + y2);
                    }
                }
            }
        }

        return -1;
    }
};