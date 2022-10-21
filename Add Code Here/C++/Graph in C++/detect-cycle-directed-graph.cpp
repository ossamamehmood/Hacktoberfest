class Solution
{

    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &curr)
    {
        vis[node] = true;
        curr[node] = true;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int newNode = adj[node][i];

            // cycle detected
            if (curr[newNode])
                return true;

            // not yet detected
            if (!vis[newNode] && dfs(newNode, adj, vis, curr))
                return true;
        }

        curr[node] = false;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), curr(V, 0);

        for (int i = 0; i < V; i++)
            if (dfs(i, adj, vis, curr))
                return true;

        return false;
    }
};