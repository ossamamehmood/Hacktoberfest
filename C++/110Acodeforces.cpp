#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff          first
#define ss          second 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int,int>
#define mii         map<int,int>
#define pqb         priority_queue<int>
#define pqs         priority_queue<int,vi,greater<int>>
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)
#define mod         100000007
#define inf         1e18
#define ps(x,y)     fixed<<setprecision(y)<<x
#define mk(arr,n,type) type*arr=new type[n];
#define w(x)        int x; cin>>x;while(x--)
// mt19937             rng(chrono::steady_clock::now.time_since_epoch().count());


//this line is for policy based datastructure
// typedef tree<int>,nulltype
// void c_p_c(){
//     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }
int32_t main(){
//    c_p_c();
    ll n;
    cin>>n;
    string s=to_string(n);
    int i=0;
    int f=0;
    int sev=0;
    while(s[i]){
        if(s[i]=='4')
        f++;
        if(s[i]=='7')
        sev++;
        i++;
    }
    if(f+sev==7 or sev+f==4)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
}


