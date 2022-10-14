#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
 
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
// using namespace __gnu_pbds;
#define gc getchar_unlocked
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, k, n) for (ll i = k; i < n; i++)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%I64d", &x)
#define ss(s) scanf("%s", s)
#define pb push_back
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << " " << x << "\n";
#define INP(v)        \
    for (auto &x : v) \
    {                 \
        cin >> x;     \
    }
#define OUT(v)            \
    for (auto &x : v)     \
    {                     \
        cout << x << " "; \
    }
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll mod = 1000000007;
const ll N = 2e5;
const ll M = 1e9 + 7;
 
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
// A.find_by_order(k-1) // gives kth smallest element
// A.order_of_key(x) // no. of elements which are less than x
 
/*void seive(ll n){
    for(ll i=2; i*i<=n; i++){
        if(a[i]==0){
            for(ll j=i; i*j<=n; j++){
                a[i*j] = 1;
            }
        }
    }
}*/
 
/*ll pw(ll a,ll b){
    if(b==0)return 1;
    ll t=pw(a,b/2);
    if(b%2)return ((a*t*t)%mod);
    else return ((t*t)%mod);
}
*/
 
void solve()
{
    ll n, k; cin>>n>>k;
    if(k%4==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(k%4==2)
    {
        cout<<"YES"<<endl;
        fo(i, n)
        {
            if((i+1)%4==1)
            {
                cout<<i+2<<" "<<i+1<<endl;
                i++;
            }
            if((i+1)%4==3)
            {
                cout<<i+1<<" "<<i+2<<endl;
            }
        }
        return;
    }
    if(k%2==1)
    {
        cout<<"YES"<<endl;
        fo(i, n)
        {
           
            cout<<i+1<<" "<<i+2<<endl;
            i++;
        }
        return;
    }
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t=1;
    cin>>t;
 
    fo(i, t)
    {
        // cout <<"Case #" << i <<": ";
        solve();
        // cout<<"A";
    }
 
    // solve();
 
    return 0;
}