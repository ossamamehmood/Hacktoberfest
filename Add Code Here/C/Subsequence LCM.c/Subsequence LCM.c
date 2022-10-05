#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using    namespace __gnu_pbds;

using    namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define dbg(x) cout<<#x<<": "<<x<<endl;

#define M  1000000007 //998244353 //

#define ll long long

#define pa pair<ll,ll>

#define ff first

#define ss second

#define pb push_back

#define pi acos(-1.0)

#define vi vector<int>

#define vll vector<ll>

#define fr(i,n,j) for(i=j;i<=n;i++)

#define rfr(i,n,j) for(i=n;i>=j;i--)

#define ct continue;

#define yo cout<<"Yes"<<endl

#define no cout<<"No"<<endl

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define all(v) v.begin(),v.end()

ll a[500005],b[10000005],c[500005],d[500003],dp[500003],inv[500005];

#define endl '\n'

long long int mod_inverse(long long int x,long long int p)//x is fact[i] and p is M-2

{

    long long int res=1,y=p;

    while(y>0)

    {

        if(y&1) res=((res%M)*(x%M))%M;

        y=y>>1;

        x=((x%M)*(x%M))%M;

    }

    return res;

}

ll ncr(ll n,ll r)//here b is for fact

{

    ll ans=d[n];

    ans=(ans*inv[r])%M;

    ans=(ans*inv[n-r])%M;

    return ans;

}

int main()

{

    fast;

    ll te,n,m,i,j,k,w,l,r,x,y,z,l2,r2,k2,k1;

    te=1;

    d[0]=c[0]=1;

    fr(i,100000,1)c[i]=(c[i-1]*2)%M,d[i]=(d[i-1]*i)%M;

    inv[100000]=mod_inverse(d[100000],M-2);

    rfr(i,99999,0)inv[i]=(inv[i+1]*(i+1))%M;

    cin>>te;

    fr(w,te,1)

    {

        cin>>n;

        fr(i,n,1)cin>>a[i],b[a[i]]++;

        x=0;

        fr(i,10000000,1)

        {

            if(b[i]==0)ct;

            x=(x+c[b[i]]-1-b[i])%M;

        }

        fr(i,10000000,1)

        {

            if(b[i]==0)ct;

            for(j=1;j*j<=i;j++)

            {

                if(i%j==0&&j<=n)

                {

                    dp[j]+=b[i];

                    if(b[i]>=j&&j>1)x=(x-ncr(b[i],j))%M;

                    z=i/j;

                    if(z!=j&&z<=n&&z>1)

                    {

                        dp[z]+=b[i];

                        if(b[i]>=z)x=(x-ncr(b[i],z))%M;

                    }

                }

            }

        }

        fr(i,n,2)

        {

            if(dp[i]>=i)

            x=(x+ncr(dp[i],i))%M;

        }

       /* for(i=2;i<=100000;i++)

        {

            z=0;

            for(j=i;j<=10000000;j+=i)

            {

                if(b[j]==0)ct;

                z+=b[j];

                if(b[j]>=i)x=(x-ncr(b[j],i))%M;

            }

            if(z>=i)x=(x+ncr(z,i))%M;

        }*/

        x=(x+M)%M;

        cout<<x<<endl;

        fr(i,n,1)b[a[i]]=0,dp[i]=0;

    }

}













