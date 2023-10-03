//link: https://leetcode.com/problems/ones-and-zeroes/description/

class Solution {
public:
    int count(string &s,char ch){
        int cnt=0;

        for(int i=0;i<s.size();++i){
            if(s[i]==ch) cnt++;
        }

        return cnt;
    }
    map<array<int,3>,int>dp;
    int solve(int i,vector<string>&str,int m,int n){
        if(m<0 or n<0 or i>=str.size()) return 0;

        if(dp.count({i,m,n})>0) return dp[{i,m,n}];

        int cnt1=count(str[i],'1');
        int cnt0=count(str[i],'0');

        int tk=0,ntk=0;

        if(cnt1<=n and cnt0<=m){
           tk=1+solve(i+1,str,m-cnt0,n-cnt1); 
        }
        ntk=solve(i+1,str,m,n);

        return dp[{i,m,n}]=max(tk,ntk);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp=map<array<int,3>,int>();
        
        return solve(0,strs,m,n);
    }
};
