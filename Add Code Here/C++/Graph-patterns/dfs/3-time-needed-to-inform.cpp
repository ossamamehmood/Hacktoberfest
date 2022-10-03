// BOTTOM UP DFS
class Solution
{
    int dfs(int i, vector<int> &parent, vector<int> &time)
    {
        if (parent[i] == -1)
            return time[i];

        time[i] += dfs(parent[i], parent, time);
        parent[i] = -1;
        return time[i];
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &inftime)
    {
        int time = 0;

        for (int i = 0; i < n; ++i)
            time = max(time, dfs(i, manager, inftime));

        return time;
    }
};

// TOP DOWN DFS
class Solution
{
    int maxTime;

    void dfs(int id, int time, vector<int> adj[], vector<int> &it)
    {
        if (it[id] == 0)
        {
            maxTime = max(maxTime, time);
            return;
        }

        for (auto &i : adj[id])
            dfs(i, time + it[id], adj, it);
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        maxTime = 0;

        // create adj list
        vector<int> adj[n];
        for (int i = 0; i < n; ++i)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);

        dfs(headID, 0, adj, informTime);
        return maxTime;
    }
};