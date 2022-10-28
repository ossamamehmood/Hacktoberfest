class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        long long int t=target;
        int n=num.size();
        vector<long long int> nums;
        for(int i=0; i<n; i++){
            nums.push_back(num[i]);
        }
        vector<int> temp;
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])  continue;
            for(int j=i+1; j<n; j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==t){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        sort(temp.begin(),temp.end());
                        if(find(v.begin(),v.end(),temp)==v.end())
                        v.push_back(temp);
                        temp.clear();
                        int third=nums[k];
                        int forth=nums[l];
                        while(k<l && third==nums[k])k++;
                        while(k<l && forth==nums[l])l--;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]>target) l--;
                    else k++;
                }
            }
        }
        return v;
    }
};
