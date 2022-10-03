#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 

void solve()
{
    ll n; cin >> n;
    ll maxF = 0;
    unordered_map<int, int> um;
    
    for(int i = 0; i < n; i++){
        ll inp; cin >> inp;
        um[inp]++;
    }
    for(auto i : um){
        if(i.second > maxF)
            maxF = i.second;
    }
    cout << n - maxF << endl;
}


int main() {

    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
