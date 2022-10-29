#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int a[m];
   for(int i=0;i<m;i++)cin>>a[i];
   bool ara[n+1];
   memset(ara,false,sizeof(ara));
   ara[0]=true;
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        int value=i+a[j];
        if(ara[i]==true){
            if(value<=n){
                ara[value]=true;
            }
        }
     }
   }
   if(ara[n]==true)cout<<"Yes"<<endl;
   else cout<<"NO"<<endl;
    return 0;
}

