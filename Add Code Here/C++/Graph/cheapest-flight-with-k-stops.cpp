// DFS + Prunning

class Solution
{
    int finalPrice;
    int flag;

    void dfs(int node, vector<int> &vis, vector<pair<int, int>> adj[], int dst, int k, int cost)
    {
        if (k < -1)
            return;
        if (node == dst)
        {
            finalPrice = min(finalPrice, cost);
            flag = 1;
            return;
        }

        vis[node] = 1;

        for (auto i : adj[node])
        {
            if (!vis[i.first])
            {
                if (cost + i.second <= finalPrice)
                { // IMP. condition, prunes redundant calls
                    dfs(i.first, vis, adj, dst, k - 1, cost + i.second);
                }
            }
        }

        vis[node] = 0;
    }

public:
    Solution()
    {
        finalPrice = INT_MAX;
        flag = -1;
    };
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        sort(flights.begin(), flights.end());
        // create adj list
        vector<pair<int, int>> adj[n];
        for (auto i : flights)
        {
            adj[i[0]].push_back(make_pair(i[1], i[2]));
        }

        // helpers
        vector<int> vis(n, 0);

        // solve function
        dfs(src, vis, adj, dst, k, 0);

        if (flag == -1)
            return -1;
        return finalPrice;
    }
};