#include "bits/stdc++.h"
#define endl '\n'
#define int long long
#define ll long long
#define pb push_back
const int N = 1e5+10;
const int INF = 1e18+10;
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int x = 0,y = 0, z = 0;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        x+=a;
        y+=b;
        z+=c;
    }
    if(x==0&&y==0&&z==0){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
 
}
 
