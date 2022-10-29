
/* this problem is like cansum just the number of coin is limited. you can.t use one coin more than one.*/

#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int dp1[100][100];
int dp[100];
void coin(int n,int m,int a[])
{
    // o(n) space comlexity
    dp[0]=1;
    for(int j=1;j<=m;j++){
        for(int i=n;i>=1;i--){
            if(i>=a[j] and dp[i-a[j]]){
                dp[i]=1;
            }
        }
    }
   for(int i=0;i<=n;i++){
        cout<<dp[i]<<endl;
    }
    // o(n*m) space comlexity
    /*dp1[0][0]=1;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if((dp1[j-1][i]) or (i>=a[j] and dp1[j-1][i-a[j]])){
                dp1[j][i]+=1;
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            cout<<dp1[j][i]<<" ";
        }
        cout<<endl;
    }*/
    if(dp[n]==1)cout<<"True"<<endl;
    else cout<<"false"<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m+1];
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    coin(n,m,a);
    return 0;
}

