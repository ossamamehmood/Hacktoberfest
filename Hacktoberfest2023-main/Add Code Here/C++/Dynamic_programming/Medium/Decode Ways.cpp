//Link: https://leetcode.com/problems/decode-ways/description/

class Solution {
public:
    int f(string &s,int i, vector<int> &dp){
        int ans=0;
        bool a,b=false;
        if(i>=s.size())
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]-'0'>=1 && s[i]-'0'<=26){
            a=true;
        }
            
        if(i+1<s.size()){
            
            int temp=10*(s[i]-'0')+(s[i+1]-'0');
            if(temp>=0 && temp<=26){
                b=true;
            }
                
        }
        if(a && b)
            return dp[i]= f(s,i+1,dp)+f(s,i+2,dp);
        else
            return dp[i]= f(s,i+1,dp);
            
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return f(s,0,dp);
        
        
    }
};
