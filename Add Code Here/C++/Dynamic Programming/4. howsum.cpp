#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int check[10000];
vector<int>v;
bool howsum(int n,int m,int a[])
{
    if(n==0)
    {
        cout<<"hurrah"<<endl;
        return true;
    }
    if(n<0)return false;
    if(check[n]==1)return true;
    if(check[n]==-1)return false;
    for(int i=0; i<m; i++)
    {
        int r=n-a[i];
        if(howsum(r,m,a)==true)
        {
            v.push_back(a[i]);
            check[n]=1;
            return true;
        }
        else
        {
            check[n]=-1;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    if(howsum(n,m,a)==true){
            cout<<"yes"<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"no ans"<<endl;
    return 0;
}

