class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int cnt=0;
        for(auto x:m){
            nums[cnt]=x.first;
            cnt++;
            
        }
        return cnt;
            
        
        
    }
};