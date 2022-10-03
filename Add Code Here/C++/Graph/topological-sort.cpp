class Solution
{

    stack<int> s;

    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = true;
        for (int i : adj[node])
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }
        s.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }

        vector<int> ans;
        while (s.size() > 0)
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};