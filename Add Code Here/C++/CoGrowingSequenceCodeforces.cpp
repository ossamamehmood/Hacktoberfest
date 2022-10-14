#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    int ans[n];
    ans[0]=0;
    for(int i=1;i<n;i++)
    {
            int x=0,f=a[i],y=a[i-1];
            int count=0;
            while(y>0 && f>0)
            {
                int r=f%2;
                int w=y%2;

                if((r&w)!=w)
                {
                    x+=pow(2,count);
                }
                count++;
                f/=2;
                y/=2;
            }
            while(y>0)
            {
                int r=y%2;
                if(r==1)
                x+=pow(2,count);
                count++;
                y/=2;
            }
            ans[i]=x;
            a[i]=a[i]^x;
    }
    for(int i=0;i<n;i++)
    cout << ans[i] << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
