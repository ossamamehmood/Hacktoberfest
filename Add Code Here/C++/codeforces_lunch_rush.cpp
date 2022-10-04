#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    long long f, t;
    cin>>n>>k>>f>>t;
    long long j1=0;
    long long j2=0;
    if(t>k)
    j1=f-(t-k);
    else
    j1=f;
    while(--n){
        cin>>f>>t;
    if(t>k)
    j2=f-(t-k);
    else
    j2=f;
    if(j2>j1)
    j1=j2;

        
    }
    cout<<j1<<endl;

    
    return 0;
}
