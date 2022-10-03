class Solution
{

    bool dfs(int node, vector<vector<int>> &adj, int color[])
    {
        if (color[node] == -1)
            color[node] = 1;

        for (auto &i : adj[node])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[node];

                if (dfs(i, adj, color) == false)
                    return false;
            }
            else if (color[i] == color[node])
                return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof(color));

        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1 && dfs(i, graph, color) == false)
                return false;
        }

        return true;
    }
};