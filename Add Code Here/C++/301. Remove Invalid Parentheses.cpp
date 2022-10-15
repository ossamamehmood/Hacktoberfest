Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]

-----------------------

class Solution {
public:
    set<string> v;
    int mx=0;
    void fnd(string s){
        string cur=s;   
        stack<char> st;
        int cnt=0;
        for(auto x:cur){
            if(x=='(') st.push(x);
            else if(x==')'){
                if(st.size()) st.pop();
                else cnt++;
            }
        }
        mx=cnt+st.size();
        mx=s.length()-mx;
    }
    
    void solve(int pos,string& cur,string& s){
        // base condition
        if(pos==s.length()){
            if(cur.size()==0) return;
            if(cur.size()!=mx) return;
            
            stack<char> st;
            for(auto x:cur){
                if(x=='(') st.push(x);
                else if(x==')'){
                    if(st.size()) st.pop();
                    else return;
                }
            }
            if(!st.size()){
                v.insert(cur);
            }
            return;
        }
        if(s.length()-pos+cur.length()<mx) return;
        
        if(s[pos]!='(' and s[pos]!=')'){
            cur+=s[pos];
            solve(pos+1,cur,s);
            cur.pop_back();
        }
        else{
            solve(pos+1,cur,s);
            cur+=s[pos];
            solve(pos+1,cur,s);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string tmp="";
        fnd(s);
        vector<string> ans;
        
        solve(0,tmp,s);
        for(auto x:v) ans.push_back(x);
        if(ans.size()==0) ans.push_back("");
        return ans;
    }
};
