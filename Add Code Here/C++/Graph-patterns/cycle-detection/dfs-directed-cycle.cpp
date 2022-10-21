// Maintain 2 vis arrays
// 1st => vis[] => simply marks if we have visited that node or not
// 2nd => curr[] => marks true if we have visited that node in current dfs call
// we turn curr[i] = false when we are backtracking from a node

class Solution
{
    bool dfs(int node, vector<int> adj[], bool vis[], bool curr[])
    {
        vis[node] = true;
        curr[node] = true;

        for (auto &i : adj[node])
            if (vis[i] == false)
            {
                if (dfs(i, adj, vis, curr) == true)
                    return true;
            }
            else if (curr[i] == true)
                return true;

        curr[node] = false;
        return false;
    }

public:
    bool isCyclic(int n, vector<int> adj[])
    {
        bool vis[n], curr[n];
        memset(vis, 0, sizeof(vis));
        memset(curr, 0, sizeof(curr));

        for (int i = 0; i < n; ++i)
            if (vis[i] == false && dfs(i, adj, vis, curr) == true)
                return true;

        return false;
    }
};