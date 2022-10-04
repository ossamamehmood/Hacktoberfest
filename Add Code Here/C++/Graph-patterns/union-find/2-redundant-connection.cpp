// https://leetcode.com/problems/redundant-connection/

// Union Find
// Simply find the first edge that forms a cycle

class Solution
{
    int find(int a, int parent[])
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }

    bool unite(int a, int b, int parent[])
    {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb)
        {
            parent[pa] = pb;
            return false;
        }
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        int parent[n + 1];
        iota(parent, parent + n + 1, 0);

        for (auto &e : edges)
        {
            if (unite(e[0], e[1], parent))
                return {e[0], e[1]};
        }

        return {}; // never execute
    }
};