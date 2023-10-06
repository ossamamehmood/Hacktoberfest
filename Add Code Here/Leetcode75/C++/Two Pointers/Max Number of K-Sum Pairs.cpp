class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		unordered_map<int, int> umap;
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
			if(umap[k - nums[i]] > 0){
			   umap[k - nums[i]]--;
				ans++;
			}
			else{
				umap[nums[i]]++;
			}
		}
		return ans;
	}
};