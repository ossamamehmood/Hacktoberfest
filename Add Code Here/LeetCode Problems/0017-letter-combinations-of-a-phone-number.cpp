class Solution {
public:
    unordered_map<char,string>mp{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    
    void recurse(string &d,int n,vector<string> &ans,string &s) {
        if(n<0)
            return;
        for(int i=0;i<mp[d[n]].size();i++) {
            s=mp[d[n]][i]+s;
            recurse(d,n-1,ans,s);            
            if(n==0)
                ans.push_back(s);
            s.erase(0,1);
        }
    }

    vector<string> letterCombinations(string digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=digits.size();
        if(n==0)
            return {};
        vector<string>ans;
        string s="";
        recurse(digits,n-1,ans,s);
        return ans;
    }
};
