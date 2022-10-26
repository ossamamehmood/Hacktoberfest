class Solution
{
public:
    int dp[100][2];
    // state=0 : ways upto ith index if only ith character is encoded
    // state=1 : ways upto ith index if previous character is also included in encoding
    int func(int i, int state, string &s)
    {
        if (i == 0 and state == 0)
            return s[i] == '0' ? 0 : 1;
        if (i == 0 and state == 1)
            return 0;
        if (dp[i][state] != -1)
            return dp[i][state];

        int val;
        if (state == 0)
        {
            if (s[i] == '0')
                val = 0;
            else
                val = func(i - 1, 0, s) + func(i - 1, 1, s);
        }
        if (state == 1)
        {
            if (s[i - 1] == '1' or (s[i - 1] == '2' and (s[i] >= '0' and s[i] <= '6')))
                val = func(i - 1, 0, s);
            else
                val = 0;
        }

        return dp[i][state] = val;
    }

    int numDecodings(string s)
    {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        return func(n - 1, 0, s) + func(n - 1, 1, s);
    }
};
