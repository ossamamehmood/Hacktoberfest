// Longest subarray with given sum
#include<bits/stdc++.h>
using namespace std;

// O(n) time, O(n) space
int longestSubarrayLen(vector<int> a, int sum){
    int n = a.size();
    unordered_map<int, int> m;
    int len = 0, s = 0;
    for(int i=0; i<n; i++){
        s += a[i];
        if(s == sum) len = i+1;
        else if(m.find(s-sum) == m.end()) m[s] = i;
        else len = max(len, i-m[s-sum]);
    }
    return len;
}

int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<longestSubarrayLen(a, sum);

    return 0;
}