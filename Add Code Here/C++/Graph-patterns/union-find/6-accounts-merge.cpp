// https://leetcode.com/problems/accounts-merge/
// AMAZING QUESTION
// hints - https://www.youtube.com/watch?v=QHniHFvxAl8

class Solution
{
    int groups;

    int find(int a, int parent[])
    {
        return parent[a] == a ? a : parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int parent[], int rank[])
    {
        int pa = find(a, parent), pb = find(b, parent);

        if (pa != pb)
        {
            --groups;
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pb] < rank[pa])
                parent[pb] = pa;
            else
            {
                parent[pa] = pb;
                ++rank[pb];
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        groups = n;
        unordered_map<string, int> emailToAccount;

        int parent[n], rank[n];
        iota(parent, parent + n, 0);
        memset(rank, 0, sizeof(rank));

        // unite common accounts
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                if (emailToAccount.find(accounts[i][j]) != emailToAccount.end())
                {
                    unite(i, emailToAccount[accounts[i][j]], parent, rank);
                }
                else
                {
                    emailToAccount[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> res(groups);
        unordered_map<int, int> groupToIdx;
        int idx = 0;

        // collect emails in groups
        for (auto &[e, i] : emailToAccount)
        {
            int p = find(i, parent);

            if (groupToIdx.find(p) == groupToIdx.end())
            {
                groupToIdx[p] = idx;
                res[idx].push_back(accounts[p][0]);
                res[idx].push_back(e);
                ++idx;
                continue;
            }

            res[groupToIdx[p]].push_back(e);
        }

        // sort accounts
        for (int i = 0; i < groups; ++i)
        {
            sort(res[i].begin() + 1, res[i].end());
        }

        return res;
    }
};