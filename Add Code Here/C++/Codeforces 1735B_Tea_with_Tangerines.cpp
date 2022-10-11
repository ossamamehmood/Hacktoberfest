#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int k = 2*a[0]-1;
        int ans=0;
        for (int i = 0; i < n; i++)
        {
            ans+=(a[i]/k);
            if(a[i]/k*k==a[i]) ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}