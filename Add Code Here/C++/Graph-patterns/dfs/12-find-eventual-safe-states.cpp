class Solution
{
    int isSafe(int i, vector<vector<int>> &g, int dp[])
    {
        if (dp[i] != 0)
            return dp[i];

        dp[i] = -1; // currently visiting
        for (auto &n : g[i])
        {
            if (isSafe(n, g, dp) == -1) // if any neighbour is unsafe
                return dp[i];           // mark this as unsafe too
        }

        // all neighbours are safe
        // mark this as safe too
        return dp[i] = 1;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        vector<int> res;

        // 0 -> unvisited
        // -1 -> currently visiting / unsafe state
        // 1 -> safe state

        for (int i = 0; i < n; ++i)
        {
            if (isSafe(i, graph, dp) == 1)
                res.push_back(i);
        }

        return res;
    }
};