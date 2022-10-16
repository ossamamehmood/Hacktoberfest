#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans, vis(V, 0);
        queue<int> nodes;

        nodes.push(0);
        vis[0] = 1;

        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            ans.push_back(node);

            for (int i = 0; i < adj[node].size(); i++)
                if (vis[adj[node][i]] == false)
                {
                    nodes.push(adj[node][i]);
                    vis[adj[node][i]] = 1;
                }
        }

        return ans;
    }
};