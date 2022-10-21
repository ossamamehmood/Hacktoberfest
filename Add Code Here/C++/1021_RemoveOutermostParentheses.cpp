class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>mini;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                if(mini.empty())
                {
                    mini.push(s[i]);
                }
                else
                {
                    mini.push(s[i]);
                    ans+=s[i];
                }
            }
            else
            {
                mini.pop();
                if(!mini.empty())
                {
                    ans+=s[i];

                }
            }
        }

       return ans;
    }
};
