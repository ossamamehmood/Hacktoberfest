#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
ll ara[1000][1000];
ll gridtraveler(ll m,ll n)
{
      if(m==1 and n==1)return 1;
      if(m==0 or n==0) return 0;
      if(ara[m][n]!=0)return ara[m][n];
      else{
            ara[m][n]=ara[n][m]=gridtraveler(m-1,n)+gridtraveler(m,n-1);
         return ara[m][n];
      }
}
int main()
{
    ll m,n;
    while(1){
        cin>>m>>n;
        cout<<gridtraveler(m,n)<<endl;
    }
    return 0;
}



