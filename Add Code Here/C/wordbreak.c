
class Solution{
public:
    vector<string> ans;
    void check(string s,int n,unordered_set<string> u,string tmp)
    {
        if(s.length()==0)
        {
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }
        for(int i=1;i<=s.length();i++)
        {
            string l=s.substr(0,i);
            string r=s.substr(i);
            if(u.find(l)!=u.end())
            check(r,n,u,tmp+l+" ");
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        //can use recursive method 
        unordered_set<string> u;
        for(int i=0;i<n;i++)
        u.insert(dict[i]);
        check(s,n,u,"");
        return ans;
    }
};
