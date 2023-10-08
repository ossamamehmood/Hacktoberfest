#include<bits/stdc++.h>
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>,int> m1;
        int ans=0;
        for(int i=0;i<coordinates.size();i++){
            for(int j=0;j<=k;j++){
                int a=(coordinates[i][0]^j);
                int b=(coordinates[i][1]^(k-j));
                if(m1.find({a,b})!=m1.end()) ans+=m1[{a,b}];
            }
            m1[{coordinates[i][0],coordinates[i][1]}]++;
            // cout<<ans;
        }
        return ans;
    }
};
