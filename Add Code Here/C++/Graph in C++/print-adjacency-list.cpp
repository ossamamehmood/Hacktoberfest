#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        for (int i = 0; i < V; i++)
        {
            vector<int> A;
            A.push_back(i);
            for (int j = 0; j < adj[i].size(); j++)
                A.push_back(adj[i][j]);
            ans.push_back(A);
        }
        return ans;
    }
};