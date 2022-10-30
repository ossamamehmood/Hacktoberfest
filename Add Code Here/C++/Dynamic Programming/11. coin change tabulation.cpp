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
int ara[1000001];

 ///runtime= O(n*m)

int  fnc(int a[],int n,int m,int num)
{
    if(ara[n]>0)return ara[n];
    for(int i=0;i<m;i++){
       if(n-a[i]==0)return 1;
       if(n-a[i]>0){
        int x=fnc(a,n-a[i],m,num);
        num=min(num,x+1);
       }
    }
    return num;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int num=100000;
        ara[i]=fnc(a,i,m,num);
    }
    cout<<ara[n]<<endl;
    return 0;
}

