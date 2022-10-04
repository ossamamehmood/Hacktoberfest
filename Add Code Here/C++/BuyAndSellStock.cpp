#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int maxProfit=0;
        int ans=prices[0];
        for(int i=0;i<n;i++){
            ans=min(ans,prices[i]);
            maxProfit=max(maxProfit,prices[i]-ans);
        }        
        return maxProfit;
    }
};