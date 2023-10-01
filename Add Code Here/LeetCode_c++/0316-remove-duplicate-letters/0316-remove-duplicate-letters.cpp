class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        unordered_map<char,int>lasto;
        for( int i=0;i<s.size();i++)
         lasto[s[i]]=i;

        stack<char>st;
        unordered_map<char,bool>vis;

        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]] )
             continue;

            while( !st.empty() && s[i]<st.top() 
            &&  lasto[st.top()]>i)
            {
                vis[st.top()]=false;
                st.pop();
            } 

            vis[s[i]]=true;
            st.push(s[i]);
        } 

        string ans="";
        while(!st.empty())
        {
            ans= st.top()+ans;
            st.pop();
        }
        return ans;
    }
};