// EASIEST METHOD

class Solution
{
    bool dfs(int node, vector<int> adj[], int dp[])
    {
        if (dp[node] == 1) // cycle
            return true;

        if (dp[node] == 0)
        {
            dp[node] = 1;
            for (auto &i : adj[node])
                if (dfs(i, adj, dp) == true)
                    return true;
        }

        dp[node] = 2;
        return false;
    }

public:
    bool isCyclic(int n, vector<int> adj[])
    {
        int dp[n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i)
            if (dp[i] == 0 && dfs(i, adj, dp) == true)
                return true;

        return false;
    }
};