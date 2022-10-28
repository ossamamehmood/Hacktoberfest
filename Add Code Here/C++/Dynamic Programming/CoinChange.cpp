#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626
#define ll long long
#define lli long long int
#define fo(i,a,n) for(int i=a;i<n;i++)
#define pr(i,arr) for(auto i:arr)

typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef map<int,int> mi;

void file_i_p()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    return a%b==0 ? b : _gcd(b,a%b);
}

int subsetSum(int W,vector<int> wt, int n)
{
    int dp[n+1][W+1];

    fo(i,0,n+1)
    {
        fo(j,0,W+1)
        {
            dp[i][j] = -1;
        }
    }
    

    

    for(int i=0;i<=W;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = (dp[i][j-wt[i-1]]) + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }


    return dp[n][W];
}

void solve()
{
    int n;
    cin>>n;

    vector<int> wt;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        wt.push_back(a);
    }

    int W;
    cin>>W;

    cout<<subsetSum(W,wt,n)<<endl;
    

}

int main() {
    
    file_i_p();

    solve();

    return 0;
}
