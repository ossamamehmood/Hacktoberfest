#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int target;
vector<vector<int> >v;
vector<int>x;                         ///this program works upto 10^5 within 1 sec
bool visit[10000];
vector<int>u;
bool bestsum(int n,int m,int a[])
{
    if(n==target)
    {
        if(v[n][0]==-1)
        {
            v[n]=x;
        }
        else if(v[n].size()>x.size())
        {
            v[n]=x;
        }
        x.pop_back();
        return true;
    }

   ///memoization  part
    if(v[n][0]!=-1)
    {
        if(v[n].size()>x.size())
        {
            v[n]=x;
             x.pop_back();
            return true;
        }
       else if(x.size()>v[n].size()){
             x.pop_back();
            return true;;
       }
       else{
             x.pop_back();
            return true;;
       }
    }

    for(int i=0; i<m; i++)
    {
        int r=n+a[i];
        if(r<=target)
        {
            x.push_back(a[i]);
            bestsum(r,m,a);
        }
    }
    if(v[n][0]==-1)
    {
        v[n]=x;
    }
    else if(v[n].size()>x.size())
    {
        v[n]=x;
    }

    x.pop_back();
    return false;
}

int main()
{
    int n,m;
    cin>>target>>m;
    int a[m];
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    n=0;
    for(int i=0; i<=target; i++)
    {
        vector<int>d;
        d.push_back(-1);
        v.push_back(d);
    }
    for(int i=0; i<=target; i++)
    {
        visit[i]=false;
    }
    sort(a, a + m, greater<int>());
    bestsum(n,m,a);
    for(int i=0; i<v[target].size(); i++)
    {
        cout<<v[target][i]<<" ";
    }
    cout<<endl;
    return 0;
}

