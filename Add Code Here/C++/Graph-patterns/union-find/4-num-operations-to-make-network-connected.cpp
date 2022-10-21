// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// Union Find Solution
// Extremely Fast

class Solution
{
    int groups, extra_wires;

    int find(int a, int parent[])
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int parent[], int rank[])
    {
        int pa = find(pa, parent), pb = find(b, parent);
        if (pa == pb)
            ++extra_wires;
        else
        {
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pa] > rank[pb])
                parent[pb] = pa;
            else
            {
                parent[pa] = pb;
                rank[pb]++;
            }
            --groups;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        groups = n;
        extra_wires = 0;

        int parent[n];
        iota(parent, parent + n, 0);
        int rank[n];
        memset(rank, 0, sizeof(rank));

        for (auto &c : connections)
        {
            unite(c[0], c[1], parent, rank);
        }

        if (extra_wires < groups - 1)
            return -1;

        return groups - 1;
    }
};