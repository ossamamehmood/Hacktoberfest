class Solution
{
    vector<int> res;

    void dfs(int node, vector<int> adj[], bool vis[])
    {
        vis[node] = true;

        for (auto &i : adj[node])
            if (vis[i] == false)
                dfs(i, adj, vis);

        // after visiting all child nodes
        res.push_back(node);
    }

public:
    vector<int> topoSort(int n, vector<int> adj[])
    {
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i)
            if (vis[i] == false)
                dfs(i, adj, vis);

        reverse(res.begin(), res.end());
        return res;
    }
};
