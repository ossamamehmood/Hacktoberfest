#include <bits/stdc++.h>
using namespace std;

#define M1 1000000007
#define M2 998244353
#define ll long long
#define ld long double
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>
#define Mapi map<int,int>
#define UMap unordered_map<int,int>
#define tolower(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define pn cout<<"NO\n";
#define py cout<<"YES\n";
#define MOD 998244353
void rotate(vector<vector<int> >&v,int n)
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            int temp=v[i][j];
            v[i][j]=v[n-1-j][i];
            v[n-1-j][i]=v[n-1-i][n-1-j];
            v[n-1-i][n-1-j]=v[j][n-1-i];
            v[j][n-1-i]=temp;
        }
    }
}
//vector<int>v={5,15,30,50,75,105,140,180,225,475};

bool fun(vector<ll>v,ll n)
{
    vector<ll>s;
    s=v;
    sort(s.begin(),s.end());
    REP(i,0,n)
    {
        if(s[i]!=v[i])
      {
            return false;
        }
    }
    return true;
}

void solve(ll i,ll j,ll &temp,string a[2],bool v[][200001],ll n)
{
    temp++;
    v[i][j]=true;
    
    if(i==0)
    {
        if(v[1][j]==false and a[1][j]=='B')
        solve(1,j,temp,a,v,n);
        else if(j<n and v[i][j+1]==false and a[i][j+1]=='B')
        solve(i,j+1,temp,a,v,n);
    }
    else
    {
         if(a[0][j]=='B' && v[0][j]==false){
            solve(0, j,temp, a, v,n);
        }else if(j+1<n){
            if(a[1][j+1]=='B'){
                solve(1, j+1, temp, a, v, n);
            }
        }
    }
    
}
 
 void bs(vll &v,ll l,ll h,ll n,ll &temp)
 {  if(l<=h)
 {
     ll mid=l+(h-l)/2;
    int f=0;
     REP(i,0,n-1)
     {
         if(abs(v[i]-mid)>abs(v[i+1]-mid))
         {
             if(v[i]>v[i+1])
             {
                 f=1;
             }
             else
             f=2;
             break;
             
         }
         
     }
    
       if(f==1)
        bs(v,mid+1, h,n,temp);
        else if(f==2)
        bs(v,l, mid-1,n,temp);
        else
        temp=mid;
 }
     
 }
void fun()
{
  int n;
  cin>>n;
  vi v(n-1);
  REP(i,0,n-1)
  cin>>v[i];
  sort(v.begin(),v.end());
  REP(i,1,n)
  if(v[i-1]!=i)
  {
    cout<<i<<endl;
    return;
  }

  cout<<n;
}
  

int32_t main()
{ 
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
  t=1;
   // cin>>t;
   while(t--)
    fun();
//fun();
return 0;
}