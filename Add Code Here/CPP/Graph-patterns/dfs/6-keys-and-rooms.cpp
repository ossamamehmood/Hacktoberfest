// ITERATIVE DFS SOLUTION
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        unordered_set<int> vis;

        // rooms matrix is nothing but adj matrix
        stack<int> dfs;
        dfs.push(0);

        while (dfs.size())
        {
            int r = dfs.top();
            dfs.pop();
            vis.insert(r);

            for (auto &i : rooms[r])
                if (vis.find(i) == vis.end())
                    dfs.push(i);
        }

        return vis.size() == n;
    }
};

// RECURSIVE DFS SOLUTION
class Solution
{
    void dfs(int r, bool vis[], vector<vector<int>> &adj)
    {
        vis[r] = true;

        for (auto &i : adj[r])
        {
            if (!vis[i])
                dfs(i, vis, adj);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        // rooms matrix is nothing but adj matrix
        dfs(0, vis, rooms);

        for (auto &i : vis)
            if (!i)
                return false;

        return true;
    }
};