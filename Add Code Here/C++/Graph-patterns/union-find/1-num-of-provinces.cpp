// https://leetcode.com/problems/number-of-provinces/
// Same as count number of connected components

// DFS => number of times, dfs performed = number of connected components
class Solution
{
    void dfs(int i, vector<vector<int>> &adj, bool vis[])
    {
        vis[i] = true;

        for (int j = 0; j < adj.size(); ++j)
        {
            if (adj[i][j] == 1 && !vis[j])
                dfs(j, adj, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        int groups = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                dfs(i, isConnected, vis);
                ++groups;
            }
        }

        return groups;
    }
};

// Union Find
// There are 'n' provinces initially, as we connect two provinces, the number of provinces decrease by 1

// Union Find
class Solution
{
    int provinces;

    int find(int a, int parent[])
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int parent[])
    {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb)
        {
            parent[pa] = pb;
            --provinces;
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        provinces = n;
        int parent[n];
        iota(parent, parent + n, 0);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j])
                    unite(i, j, parent);
            }
        }

        return provinces;
    }
};