class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
         k=k%nums.size();
        int tmp=nums.size()-k;
        
        reverse(nums.begin(),nums.begin()+tmp);
        reverse(nums.begin()+tmp,nums.end());
        
        reverse(nums.begin(),nums.end());
    }
};