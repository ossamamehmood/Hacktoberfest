class Solution
{
    bool bfs(int node, vector<int> adj[], bool vis[])
    {
        vis[node] = true;
        queue<pair<int, int>> q; // node, parent
        q.push({node, -1});

        while (q.size())
        {
            int v = q.front().first, parent = q.front().second;
            q.pop();

            for (auto &i : adj[v])
                if (vis[i] == false)
                {
                    vis[i] = true;
                    q.push({i, v});
                }
                else if (i != parent) // node not parent but already visited ==> cycle
                    return true;
        }
        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i)
            if (vis[i] == false && bfs(i, adj, vis) == true)
                return true;

        return false;
    }
};