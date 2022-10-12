#include<bits/stdc++.h>
using namespace std;
int maxSubArrSum(int n, int a[])
{
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>ans)
        {
            ans=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
       cout<<maxSubArrSum(n,a);
    }
    return 0;
}
