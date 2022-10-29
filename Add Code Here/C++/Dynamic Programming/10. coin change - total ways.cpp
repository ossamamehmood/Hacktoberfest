
/*this code gives total number of ways to make the coin */


#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
///for o[n] space complexity
int way[100000];
void coin(int n,int m,int a[])
{
    way[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i>=a[j]){
                way[i] += way[i-a[j]];
            }
        }
    }
    //for(int i=0;i<=n;i++)cout<<"i= "<<i<<"  value= "<<way[i]<<endl;
    if(way[n]==1)cout<<wa[n]<<endl;
    else cout<<"No"<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    coin(n,m,a);
    return 0;
}
/// for o[m*n]space complexity
/*
int v[100][100];
void coin(int n,int m,int a[])
{
    for(int i=0;i<m;i++)v[i][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++){
            if(a[i]>j){
                    if(i>0)
                         v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=v[i-1][j]+v[i][j-a[i]];
            }
        }
    }
    cout<<v[m][n]<<endl;
}
*/
