class Solution
{
    bool dfs_cycle(int node, vector<int> &vis, int parent, vector<int> adj[])
    {
        vis[node] = true;
        for (int i : adj[node])
        {
            if (!vis[i])
            {
                if (dfs_cycle(i, vis, node, adj))
                {
                    return true;
                }
            }
            else if (i != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs_cycle(i, vis, -1, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};