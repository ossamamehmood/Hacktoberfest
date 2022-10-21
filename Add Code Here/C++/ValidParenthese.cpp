class Solution {
public:
    bool isValid(string s) {
        int length=s.size();
        vector<char> brackets;
        for(int i=0;i<length;i++)
        {
            if(brackets.empty())
            {
                brackets.push_back(s[i]);
            }
            else if( brackets.back() == '(' && s[i] == ')' || brackets.back() == '[' && s[i] == ']' || brackets.back() == '{' && s[i] == '}' )
            {
                brackets.pop_back();
            }
            else
            {
                brackets.push_back(s[i]);
            }
        }
        if(brackets.empty())
        {
            return true;
        }
            return false;
        
        
        
    }
};
