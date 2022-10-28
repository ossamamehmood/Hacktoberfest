class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int> m;
        for(auto it:nums)
            m[it]++;
        priority_queue<pair<int,int> >ans;
        for(auto it: m)
            ans.push({it.second,it.first});
        return ans.top().second;
    }
};
