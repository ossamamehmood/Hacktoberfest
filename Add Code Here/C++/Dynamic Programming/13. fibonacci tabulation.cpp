#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    memset(a,0,sizeof(a));
    a[1]=1;
    for(int i=0;i<n;i++){     //1st method
        if(i==n-1){
            a[i+1]+=a[i];
        }
        else{
            a[i+1]+=a[i];
            a[i+2]+=a[i];
        }
    }
     /*for(int i=2;i<=n;i++){   // 2nd method
        a[i]+=a[i-1]+a[i-2];
    }*/
    //for(int i=0;i<=n;i++)cout<<a[i]<<endl;
    cout<<a[n]<<endl;
    return 0;
}



