// Exactly Same As 01 Matrix
// 1. Modified BFS
class Solution
{
public:
    int maxDistance(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size(), d[] = {-1, 0, 1, 0, -1};
        queue<int> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                {
                    g[i][j] = 0;
                    q.push(i * n + j);
                }
                else
                    g[i][j] = INT_MAX;

        if (q.size() == 0 || q.size() == m * n)
            return -1;

        int res = 0;

        while (q.size())
        {
            int y = q.front() % n, x = (q.front() - y) / n;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + d[i], ny = y + d[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[x][y] + 1 < g[nx][ny])
                    g[nx][ny] = g[x][y] + 1, q.push(n * nx + ny);
            }
        }

        for (int i = 0; i < m; ++i)
            res = max(res, *max_element(g[i].begin(), g[i].end()));

        return res;
    }
};

// 2. BFS USING 2 QUEUES
// https://leetcode.com/problems/as-far-from-land-as-possible/discuss/360963/C%2B%2B-with-picture-DFS-and-BFS
class Solution
{
public:
    int maxDistance(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size(), d[] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q, q1;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                    for (int k = 0; k < 4; ++k)
                        q.push({i + d[k], j + d[k + 1]});

        int steps = 1;

        while (q.size())
        {
            ++steps;
            while (q.size())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                if (x < 0 || y < 0 || x == m || y == n || g[x][y] != 0)
                    continue;
                g[x][y] = steps;

                for (int k = 0; k < 4; ++k)
                    q1.push({x + d[k], y + d[k + 1]});
            }
            swap(q, q1);
        }

        return steps == 2 ? -1 : steps - 2;
    }
};

// 3. DP Method same as 01 Matrix
// check that, not writing it again