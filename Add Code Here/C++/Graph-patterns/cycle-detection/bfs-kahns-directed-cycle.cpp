class Solution
{
public:
    bool isCyclic(int n, vector<int> adj[])
    {
        int in[n], cnt = 0;
        memset(in, 0, sizeof(in));

        for (int i = 0; i < n; ++i)
        {
            for (auto &v : adj[i])
                ++in[v];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (in[i] == 0)
                q.push(i), cnt++;

        while (q.size())
        {
            int node = q.front();
            q.pop();

            for (auto &v : adj[node])
            {
                if (--in[v] == 0)
                {
                    q.push(v);
                    cnt++;
                }
            }
        }

        return cnt != n;
    }
};