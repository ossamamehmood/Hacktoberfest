class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vect;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int c;
                c = nums[i]+nums[j];
                if(c == target){
                    // vector<int> vect;
                    vect.push_back(i);
                    vect.push_back(j);
                    
                }
            }
        }
        return vect;
    }
};
