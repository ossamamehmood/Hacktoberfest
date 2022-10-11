class Solution {
private:
     void solution(vector<int> nums,int index,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
       for(int j=index;j<nums.size();j++){
           if(st.find(nums[j])!=st.end()) continue;
           st.insert(nums[j]);
           swap(nums[index],nums[j]);
           solution(nums,index+1,ans);
           swap(nums[index],nums[j]);
       }
     }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solution(nums,index,ans);
        return ans;        
    }
};