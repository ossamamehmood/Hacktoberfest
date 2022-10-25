class Solution {
public:
    int reversenumber(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            int num=reversenumber(nums[i]);
            m[num]++;
        }
        return m.size();
    }
};