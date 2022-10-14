#include <vector>
using namespace std;

class Solution
{
    void solve(int node, vector<int> adj[], vector<int> &ans, vector<int> &vis)
    {
        vis[node] = 1;
        ans.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            int newNode = adj[node][i];
            if (!vis[newNode])
                solve(newNode, adj, ans, vis);
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans, vis(V, 0);
        solve(0, adj, ans, vis);
        return ans;
    }
};