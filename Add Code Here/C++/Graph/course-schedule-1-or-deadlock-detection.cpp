class Solution
{
    bool possible = true, impossible = false;

    // returns true if there is a cycle
    bool dfs(int node, vector<int> &vis, vector<int> &rec, vector<int> adj[])
    {
        vis[node] = rec[node] = 1;

        for (auto i : adj[node])
            if (!vis[i])
                if (dfs(i, vis, rec, adj))
                    return true;
                else if (rec[i])
                    return true;

        rec[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses == 1)
            return possible;

        // create adj list
        vector<int> adj[numCourses];
        for (auto i : prerequisites)
            adj[i[0]].push_back(i[1]);

        // helpers
        vector<int> vis(numCourses, 0), rec(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
            if (!vis[i])
                if (dfs(i, vis, rec, adj))
                    return impossible;

        return possible;
    }
};