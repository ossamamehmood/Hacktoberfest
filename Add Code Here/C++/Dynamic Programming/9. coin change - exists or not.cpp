
/* this problem is just like cansum problem*/

#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int possible[100000];
void coin(int n,int m,int a[])           ///  "a|=b"  means  a=a | b  only true one is initialized
{
    possible[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i>=a[j]){
                possible[i] |= possible[i-a[j]];
            }
        }
    }
    //for(int i=0;i<=n;i++)cout<<"i= "<<i<<"  value= "<<possible[i]<<endl;
    if(possible[n]==1)cout<<"Yes"<<endl;
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
