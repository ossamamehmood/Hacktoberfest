// SIMPLE UNION FIND SOLUTIONS

class Solution
{
    int find(int a, int parent[])
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int parent[], int rank[])
    {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb)
        {
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pa] > rank[pb])
                parent[pb] = pa;
            else
                parent[pa] = pb;
        }
    }

    bool check(int a, int b, int parent[])
    {
        return find(a, parent) == find(b, parent);
    }

public:
    bool equationsPossible(vector<string> &eq)
    {
        int parent[26], rank[26] = {};
        iota(parent, parent + 26, 0);

        for (auto &s : eq)
        {
            if (s[1] == '!')
            {
                if (s[0] == s[3])
                    return false;
                continue;
            }
            int a = s[0] - 'a', b = s[3] - 'a';
            unite(a, b, parent, rank);
        }

        for (auto &s : eq)
        {
            if (s[1] == '=')
                continue;
            int a = s[0] - 'a', b = s[3] - 'a';
            if (check(a, b, parent))
                return false;
        }

        return true;
    }
};