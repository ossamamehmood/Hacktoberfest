#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// SHORTEST PATH IN WEIGHTED DAG

// dfs
void dfs(int node, vector<pair<int, int>> adj[], bool vis[], vector<int> &res)
{
    vis[node] = true;

    for (auto &i : adj[node])
        if (vis[i.first] == false)
            dfs(i.first, adj, vis, res);

    res.push_back(node);
}

// Top sort
vector<int> topSort(int n, vector<pair<int, int>> adj[])
{
    bool vis[n];
    memset(vis, 0, sizeof(vis));

    vector<int> res;

    for (int i = 0; i < n; ++i)
        if (vis[i] == false)
            dfs(i, adj, vis, res);

    reverse(res.begin(), res.end());
    return res;
}

// Main Function
void shortestPaths(int src, int n, vector<pair<int, int>> adj[])
{
    vector<int> order = topSort(n, adj);
    int dis[n];
    for (int i = 0; i < n; ++i)
        dis[i] = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        int node = order[i];
        if (dis[node] != INT_MAX)
        {
            // relax adj edges
            for (auto &v : adj[node])
            {
                if (dis[node] + v.second < dis[v.first])
                    dis[v.first] = dis[node] + v.second;
            }
        }
    }

    // Print Distances
    for (auto &i : dis)
        cout << i << " ";
}