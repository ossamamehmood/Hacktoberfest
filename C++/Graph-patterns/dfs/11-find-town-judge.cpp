// 2 pass method
// O(n)
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        array<int, 1002> in = {}, out = {};

        for (auto &r : trust)
            ++out[r[0]], ++in[r[1]];

        for (int i = 1; i <= n; ++i)
        {
            if (out[i] == 0 && in[i] == n - 1)
                return i;
        }

        return -1;
    }
};
