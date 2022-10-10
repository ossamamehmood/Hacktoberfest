#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int fun(int index,string&s,vector<int>& dp,map<string,string>& hardcoded, string curr,set<string>& disset, long long int mod){
if(index<0){
    auto it=disset.find(curr);
    if(it==disset.end()){
        disset.insert(curr);
        return 1;
    }
    return 0;
}
if(dp[index]!= -1)return dp[index];
long long int takingone=fun(index-1,s,dp,hardcoded,hardcoded[s.substr(index, 1)+curr],disset,mod);
long long int takingtwo = 0;
if(index-1 >= 0 && hardcoded.find(s.substr(index-1,2)) != hardcoded.end())
    takingtwo = fun(index-2,s,dp,hardcoded,hardcoded[s.substr(index-1,2)]+curr,disset,mod);
    return dp[index] = (takingone+takingtwo)%998244353;
}
long long int solve(){
    string s;
    cin >> s;
    long long int n=s.length();
    vector<int> dp(n, -1);
    map<string,string> hardcoded{{"a","01"},{"b","10"},{"ab","010"},{"ba","101"}};
    set<string> disset;
    cout<<fun(n-1,s,dp,hardcoded,"",disset,998244353)<<endl;
    return 0;
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
