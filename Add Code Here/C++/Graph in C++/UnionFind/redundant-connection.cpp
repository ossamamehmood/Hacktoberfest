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
        if (pa == pb)
            return true;

        parent[pa] = pb; // connect!
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        int parent[n + 1];
        iota(parent, parent + n + 1, 0);

        for (auto &e : edges)
        {
            int from = e[0], to = e[1];
            if (unite(from, to, parent))
            {
                return {from, to};
            }
        }

        return {};
    }
};