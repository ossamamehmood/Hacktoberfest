#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m+1][n+1];
    memset(a,0,sizeof(a));
    a[1][1]=1;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j==n and i<m){
                a[i+1][j]+=a[i][j];
            }
            else if(j<n and i<m){
                a[i+1][j]+=a[i][j];
                a[i][j+1]+=a[i][j];
            }
            else if(i==m and j<n){
                   a[i][j+1]+=a[i][j];
            }
        }
    }
    cout<<a[m][n]<<endl;
    return 0;
}

