class Solution {
public:
#define ll long long
    
    ll dp[1<<17];
    
    ll dfs(ll mask, ll x, vector<int> &power) {
        if(mask==0) return 0;
        if(dp[mask]!=-1) return dp[mask];
        ll ans = 1e18;
        for(ll i=0; i<power.size(); i++) {
            if(mask & (1LL<<i)) ans = min(ans,(power[i]+x-1)/x + dfs(mask^(1LL<<i),x+1,power));
        }
        return dp[mask]=ans;
    }
    
    long long minimumTime(vector<int>& power) {
        ll n = power.size();
        memset(dp,-1,sizeof(dp));
        ll mask = -1+(1LL<<n);
        return dfs(mask,1,power);
    }
};
