#include<bits/stdc++.h>
#define        ll        long long int
#define        ls        unsigned long long
#define         eps       1e-9
#define         M_E      2.718281828
#define         M_PI     3.1416
#define        MAX       500
#define        frin          for(ll i=0;i<n;i++)
#define        frjn          for(ll j=0;j<n;j++)
const int   mod=1e9+7;
using namespace std;

/// W=total weight
/// array a = weights of the items
/// array v = values of the items
/// n = number of items

int knapsack(int W,int a[],int v[],int n)
{
    int value[W+1];
    value[0]=0;
    for(int w=1;w<=W;w++)
    {
        value[w]=0;
        for(int i=0;i<n;i++)
        {
           if(a[i]<=w){
            int val=value[w-a[i]]+v[i];
            if(val>value[w]){
                value[w]=val;
            }
           }
        }
    }
    return value[W];
}
int main()
{
    int n,w;
    cin>>w>>n;
    int a[n];
    int v[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<knapsack(w,a,v,n)<<endl;
    return 0;
}
