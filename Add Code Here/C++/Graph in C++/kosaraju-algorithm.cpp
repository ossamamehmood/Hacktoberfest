class Solution
{
    stack<int> nodes;
    vector<int> vis;

    void dfs1(int node, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
            if (!vis[i])
                dfs1(i, adj);
        nodes.push(node);
    }

    void dfs2(int node, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
            if (!vis[i])
                dfs2(i, adj);
    }

    void reverse(vector<int> adj[], int V, vector<int> rev[])
    {
        for (int i = 0; i < V; i++)
            for (auto j : adj[i])
                rev[j].push_back(i);
    }

public:
    int kosaraju(int V, vector<int> adj[])
    {

        vis.resize(V, 0);

        // dfs - 1
        for (int i = 0; i < V; i++)
            if (!vis[i])
                dfs1(i, adj);

        // reverse adj list
        vector<int> rev[V];
        reverse(adj, V, rev);

        // reset vis array
        for (int i = 0; i < V; i++)
            vis[i] = 0;

        // dfs - 2
        int count = 0;
        while (!nodes.empty())
        {
            int node = nodes.top();
            nodes.pop();

            if (!vis[node])
            {
                count++;
                dfs2(node, rev);
            }
        }

        return count;
    }
};