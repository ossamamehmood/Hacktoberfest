#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
vector<vector<int>>vec;
vector<int>x;
void fnc(int a[],int n,int m)
{
    int num=1000000;
    for(int i=0; i<m; i++)
    {
        if(n-a[i]==0)               ///if coin exists in the ara just return the coin
        {
            x.push_back(a[i]);
            return;
        }
        if(n-a[i]>0)                 ///else find out which is the optimal number
        {
            int sz=vec[n-a[i]].size();
            num=min(num,sz);
        }
    }
    for(int i=0; i<m; i++)    /// after finding the optimal number return the solution
    {
        int sz=n-a[i];
        if(sz>0)
        {
            if(vec[sz].size()==num)
            {
                x.push_back(a[i]);
                for(int j=0; j<vec[sz].size(); j++)
                {
                    x.push_back(vec[sz][j]);
                }
                break;
            }
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++)cin>>a[i];
    x.push_back(0);
    vec.push_back(x);
    for(int i=1; i<=n; i++)
    {
        x.clear();
        fnc(a,i,3);
        vec.push_back(x);
    }
    cout<<vec[n].size()<<endl;
    for(int j=0; j<vec[n].size(); j++)
    {
        cout<<vec[n][j]<<" ";
    }
    cout<<endl;
    return 0;
}

