// BEAUTIFUL QUESTION

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size(), d[5] = {-1, 0, 1, 0, -1}, cnt = 0;

        queue<int> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == 2)
                    q.push(n * i + j);
                else if (g[i][j] == 1)
                    ++cnt;

        if (cnt == 0)
            return 0;

        int mins = -1;

        while (!q.empty())
        {
            int sz = q.size();
            ++mins;

            while (sz--)
            {
                int y = q.front() % n, x = (q.front() - y) / n;
                q.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + d[i], ny = y + d[i + 1];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == 1)
                        --cnt, g[nx][ny] = -1, q.push(n * nx + ny);
                }
            }
        }

        if (cnt != 0)
            return -1;

        return mins;
    }
};