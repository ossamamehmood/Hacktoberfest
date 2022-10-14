// 547
class Solution
{
    int find(int a, int parent[])
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }

    void unite(int &a, int &b, int parent[], int &c)
    {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb)
        {
            parent[pa] = pb;
            --c;
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isC)
    {
        int n = isC.size();
        int parent[n + 1];
        iota(parent, parent + n, 0);
        int groups = n;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isC[i][j] == 1)
                {
                    unite(i, j, parent, groups);
                }
            }
        }

        return groups;
    }
};