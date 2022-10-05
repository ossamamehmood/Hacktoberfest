// Kahn's Algorithm
class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &pre)
    {
        int in[n];
        memset(in, 0, sizeof(in));

        vector<int> adj[n];
        // indegrees + adj list
        for (int i = 0; i < pre.size(); ++i)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            ++in[pre[i][0]];
        }

        queue<int> q;

        for (int i = 0; i < n; ++i)
            if (in[i] == 0)
                q.push(i);

        int cnt = 0;
        vector<int> res(n);
        while (q.size())
        {
            int node = q.front();
            res[cnt++] = node;
            q.pop();

            for (int i = 0; i < adj[node].size(); ++i)
                if (--in[adj[node][i]] == 0)
                    q.push(adj[node][i]);
        }

        if (cnt == n)
            return res;

        return {};
    }
};