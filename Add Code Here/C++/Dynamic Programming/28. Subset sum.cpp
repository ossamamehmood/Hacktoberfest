#include<bits/stdc++.h>
#define        ll       long long int
#define   mx        6
using namespace std;
void tabulation()
{
      ll n,m;
       cin>>n>>m;
        vector<ll>v;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        ll a[n+1][m+1];
        memset(a,0,sizeof(a));

        for(ll i=0;i<n+1;i++)a[i][0]=1;

         for(ll i=1;i<n+1;i++){
            for(ll j=1;j<m+1;j++){
                if(a[i-1][j]==1)a[i][j]=1;
                else{
                    ll sub=j-v[i-1];
                    if(sub<0)a[i][j]=0;
                    else if(a[i-1][sub]==1)a[i][j]=1;
                    else a[i][j]=0;
                }
            }
        }

       if(a[n][m]==1)cout<<"Yes"<<endl;
       else cout<<"No"<<endl;
}
bool solve(vector<ll>&v,bool mark[],ll n)
{
    if(n==0)return true;
    if(n<0)return false;
    for(ll i=0; i<v.size(); i++)
    {
        if(mark[i]==false)
        {
            ll sub=n-v[i];
            mark[i]=true;
            if(solve(v,mark,sub)){
                    return true;
            }
            else
            {
                mark[i]=false;
            }
        }
    }
    return false;
}
void recursion()
{
      ll n,m;
        cin>>n>>m;
        vector<ll>v;
        for(ll i=0;i<v.size();i++){
            ll x;
            cin>>x;
            v.push_back(x);
        }
        bool mark[n];
        memset(mark,false,sizeof(mark));
        vector<ll>ans;
        if(solve(v,mark,m))
            cout<<"yes"<<endl;
        else cout<<"no"<<endl;
}
int main()
{
    tabulation();
   // recursion();
    return 0;
}


