// Method 1 = Union Find
// Time = 108ms, Space = 41.9mb

class Solution
{
    vector<int> parent;

    int dsf(int x)
    {
        return (parent[x] == -1) ? x : parent[x] = dsf(parent[x]);
    }

    void dsu(int u, int v)
    {
        u = dsf(u);
        v = dsf(v);

        if (u != v)
            parent[u] = v;
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // invalid case
        if (connections.size() < n - 1)
            return -1;

        // parent
        parent.resize(n, -1);

        for (auto i : connections)
            dsu(i[0], i[1]);

        int count = 0;
        for (auto i : parent)
        {
            if (i == -1)
                count += 1;
        }

        return count - 1;
    }
};

// Method 2 = Simple DFS
// Time = 132ms, Space = 55.2mb

#define pb push_back

class Solution
{
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // invalid case
        if (connections.size() < n - 1)
            return -1;

        // create adj list
        vector<int> adj[n];
        for (auto i : connections)
        {
            adj[i[0]].pb(i[1]);
            adj[i[1]].pb(i[0]);
        }

        // create helpers
        vector<int> vis(n, 0);

        // count disjoint computers
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count - 1;
    }
};