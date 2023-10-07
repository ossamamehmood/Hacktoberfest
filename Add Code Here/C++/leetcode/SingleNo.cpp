//136. Single Number
//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//You must implement a solution with a linear runtime complexity and use only constant extra space.



class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ans=0;
	int n=nums.size();
	for(int i=0;i<n;i++){
		ans=ans^nums[i];
	}
	return ans;
    }
};
