#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define vi vector<ll>
#define endl "\n"
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define rep(i,n) for(ll i=0;i<n;i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(a,n) for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n) for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ep 1e-10
#define pi pair<ll,ll>
#define inf 10e9
#define N 1000000
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
stack<ll> s;
#define N 1000000
vector<ll> adj[N];
vector<bool> visited(N,0);
void DFSUtil(ll u)
{
    visited[u] = true;
    for (ll i=0; i<adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            DFSUtil(adj[u][i]);
        }
    }
    s.push(u);
}
void DFS(ll n)
{
    for (ll u=1; u<=n; u++)
    {
        if (visited[u] == false)
        {
            DFSUtil(u);
        }
    }
}
void aE(ll u, ll v)
{
    adj[u].push_back(v);
}
int main()
{

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        aE(a,b);
    }
    DFS(n);
    while(s.empty()==0)
    {
        cout<<s.top()<<endl;
        s.pop();
    }

}
