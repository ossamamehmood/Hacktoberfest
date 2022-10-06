#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        char op = '+';
        int curr = 0;
        vector<int> stk;

        for (int i = 0; i < s.size(); ++i)
        {

            if (isdigit(s[i]))
                curr = curr * 10 + (s[i] - '0');

            if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (op == '+')
                    stk.push_back(curr);
                else if (op == '-')
                    stk.push_back(curr * (-1));
                else if (op == '*')
                {
                    int num = stk.back();
                    stk.pop_back();
                    stk.push_back(num * curr);
                }
                else if (op == '/')
                {
                    int num = stk.back();
                    stk.pop_back();
                    stk.push_back(num / curr);
                }

                curr = 0;
                op = s[i];
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};