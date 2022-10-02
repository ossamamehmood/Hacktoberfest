//  3 SUM PROBLEM
// Problem Link: https://leetcode.com/problems/3sum/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            
        vector<vector<int>> ans;
        
        int n = nums.size();
        
        if(n<3){
            return ans;
        }
        
        sort(nums.begin(), nums.end());
                
        for(int i=0;i<n;i++){
            
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                
                int j = i+1;
                int k = n-1;
                
                while(j<k){
                    
                    if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        
                        ans.push_back(temp);
                        
                        while(j<k && (nums[j]==nums[j+1])){
                            j++;
                        }
                        while(j<k && (nums[k]==nums[k-1])){
                            k--;
                        }
                        
                        j++;
                        k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]<0){
                        j++;
                    }
                    else{
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};