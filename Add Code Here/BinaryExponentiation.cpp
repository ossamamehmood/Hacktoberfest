#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+2, MOD=1e9+7;

int power(int a, int n){
    a%=MOD;
    int ans=1;
    while(n>0){
        if(n&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        n=n>>1; //right shift
    }
    return ans;
}

signed main(){
    int a, n;
    cin>>a>>n;
    cout<<power(a,n);
    return 0;
}

/*
INPUT:
42543523635653 6
OUTPUT:
713143349
*/

/*
INPUT: 
2 5
OUTPUT:
32
*/