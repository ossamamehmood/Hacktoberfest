#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int check[10000];
bool cansum(int n,int m,int a[])
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
        if(cansum(r,m,a)==true)
        {
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
    if(cansum(n,m,a)==true)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
