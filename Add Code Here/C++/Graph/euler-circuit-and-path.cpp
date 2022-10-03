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

    int connected(int V, vector<int> adj[])
    {
        int components = 0;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && adj[i].size() > 0)
            {
                components += 1;
                dfs(i, adj, vis);
            }
        }

        if (components == 0)
            return 0; // euler graph
        if (components == 1)
            return 2; // connected graph
        return 1;     // disconnected components
    }

public:
    int isEularCircuit(int V, vector<int> adj[])
    {

        // connectivity check
        int status = connected(V, adj);
        if (status == 0)
        {
            // all disconnected nodes
            // euler graph
            return 2;
        }
        else if (status == 1)
        {
            // disconnected components have edges
            // non eulerian graph
            return 0;
        }

        // degree check
        int oddDeg = 0;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() & 1)
                oddDeg++;
        }
        if (oddDeg == 0)
            return 2;
        if (oddDeg == 2)
            return 1;
        return 0;
    }
};
