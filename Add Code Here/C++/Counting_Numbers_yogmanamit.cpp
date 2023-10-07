#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ii = pair<ll,ll>;
 
const ll mod = 1e9+7;
 
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define len(x) ((ll)((x).size()))
#define rep(i,x) for(ll i=0;i<(x);i++)
#define all(x) (x).begin(),(x).end()
 
struct segtree_iterative{
    int n;vector<ll> t;
    segtree_iterative(vector<ll> arr_){
        n=(int)arr_.size();
        t.resize(2*n+5);
        for(int i=0;i<n;i++)t[i+n]=arr_[i];
        build();
    }
    void build(){
        for(int i=n-1;i>=1;--i)
            t[i] = t[i<<1] + t[i<<1|1];
    }
    void update(int pos,ll val){
        for(t[pos+=n] = val; pos>1; pos>>=1)
            t[pos>>1] = t[pos] + t[pos^1];
    }
    ll query(int l,int r){
        ll res=0;
        // range [l,r]
        for(l+=n, r+=n; l<=r; l>>1 , r>>1){
            if(l&1)     res+=t[l++];
            if(!(r&1))  res+=t[r--];
        }
        // // range [l,r)
        // for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        //     if (l&1) res += t[l++];
        //     if (r&1) res += t[--r];
        // }
        return res;
    }
    void range_update(int l,int r,ll val){
        for(l+=n, r+=n; l<=r; l>>1, r>>1){
            if(l&1)     t[l++] += val;
            if((r&1))   t[r--] += val;
        }
        // for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        //     if (l&1) t[l++] += value;
        //     if (r&1) t[--r] += value;
        // }
    }
    ll point_query(int p){
        ll res=0;
        for(p+=n; p>0; p>>=1) res+=t[p];
        return res;
    }
    void push() {
        // if at some point after modifications we need to inspect all the elements in the array, we can push all the modifications to the leaves using the following code. After that we can just traverse elements starting with index n. This way we reduce the complexity from O(nlog(n)) to O(n) similarly to using build instead of n modifications.
        for (int i = 1; i < n; ++i) {
            t[i<<1] += t[i];
            t[i<<1|1] += t[i];
            t[i] = 0;
        }
    }
    // just pass the 0-index vector arr for intialization
    // build is carried out automatically
    // update(idx,val) -> idx is 0-indexed position in vector arr 
    // query(l,r) -> l,r is 0-based index in vector arr 
}typedef(segtree_iterative);
 
ll dp[10001][1024];
ll n,m;
ll rec(int idx,int vis){
    if(idx>=m*n){return vis==((1<<n)-1);}
    if(~dp[idx][vis]){
        return dp[idx][vis];
    }
    ll ans=0;
    if(vis&(1<<(n-1))){
        if((!(vis&1)) && (idx%n)){
            ans=rec(idx+1,
                (vis<<1|3)&((1<<n)-1));
        }
        ans=(ans+rec(idx+1,(vis<<1)&((1<<n)-1)))%mod;
    }else{
        ans=rec(idx+1,(vis<<1|1)&((1<<n)-1));
    }
    return dp[idx][vis]=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cout<<rec(0,(1<<n)-1)<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}