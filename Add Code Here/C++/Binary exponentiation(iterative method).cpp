#include<bits/stdc++.h>
using namespace std;
long long int exponentiation(long long int x,long int y)
{
    long long int res=1;
    if(y==0)
    {
        return 1;
    }
    while(y>0)
    {
        if(y&1)
        {
            res=res*x;
        }
        y=y>>1;
        x=x*x;
    }
    return res;
}
int main()
{
    long long int x,y;
    cin>>x>>y;
    long long int ans=exponentiation( x, y);
    cout<<ans;
}
