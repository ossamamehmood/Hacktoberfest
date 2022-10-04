class Solution
{
public:
    vector<int> topoSort(int n, vector<int> adj[])
    {
        int in[n];
        memset(in, 0, sizeof(in));

        for (int i = 0; i < n; ++i)
            for (auto &v : adj[i])
                ++in[v];

        queue<int> q;

        for (int i = 0; i < n; ++i)
            if (in[i] == 0)
                q.push(i);

        vector<int> res;
        while (q.size())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for (auto &i : adj[node])
                if (--in[i] == 0)
                    q.push(i);
        }

        return res;
    }
};