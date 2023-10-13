class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        vector<int> vec;
        int i=0,j=0;
        int d1=nums1.size(),d2=nums2.size();
        for(;i<d1 && j<d2;){
            if(nums1[i][0]<nums2[j][0]){
                ans.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i][0]==nums2[j][0]){
                vec.push_back(nums1[i][0]);
                vec.push_back(nums1[i][1]+nums2[j][1]);
                ans.push_back(vec);
                i++;
                j++;
                vec.clear();
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        for(;i<d1;i++){
            ans.push_back(nums1[i]);
        }
        for(;j<d2;j++){
            ans.push_back(nums2[j]);
        }
        return ans;
    }
};
