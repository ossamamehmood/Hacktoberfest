// Question number 2 from Leetcode BiWeekly Contest 114
// Question id: 2870

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums) mp[it]++;
        int ans=0;
        for(auto it: mp){
            if(it.second==1) return -1;
            if(it.second==2 || it.second==4) ans+= it.second/2;
            else if(it.second%3==0) ans+= it.second/3;
            else{
                while(it.second%3!=0){
                    it.second-=2;
                    ans++;
                }
                ans += it.second/3;
            }
        }
        return ans;
    }
};