class Solution
{
    bool dfs(int node, int parent, vector<int> adj[], bool vis[])
    {
        vis[node] = true;

        for (auto &i : adj[node])
            if (vis[i] == false)
            {
                if (dfs(i, node, adj, vis) == true)
                    return true;
            }
            else if (i != parent)
                return true;

        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i)
            if (vis[i] == false && dfs(i, -1, adj, vis) == true)
                return true;

        return false;
    }
};