#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++)cin>>a[i];
    vector<vector<int> >v;

    for(int i=0; i<=n; i++)
    {
        vector<int>x;
        x.push_back(0);
        v.push_back(x);
    }
    v[0].pop_back();
    v[0].push_back(1);

    for(int i=0; i<n; i++)
    {
        if(v[i][0]>0)
        {
            for(int j=0; j<m; j++)
            {
                int x=i+a[j];
                if(x<=n)
                {
                    v[x].pop_back();
                    if(i>0)v[x]=v[i];        //i>0 condition is used because at i=0  v[0][0]=1 and we can't copy that 1 in v[x];
                    v[x].push_back(a[j]);
                }
            }
        }
    }
    for(int i=0;i<v[n].size();i++)cout<<v[n][i]<<" ";
    cout<<endl;
    return 0;
}

