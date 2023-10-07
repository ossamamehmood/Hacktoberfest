//  Using HashMap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int pair = target - nums[i];
            if(map.count(pair)) return {map[pair], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
