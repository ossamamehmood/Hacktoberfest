class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0,d=nums.size(),j=0;
        for(int i=0;i<d;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                nums[j++]=nums[i];
            }
        }
        int i=1;
        while(count--){
            nums[d-i]=0;
            i++;
        }
    }
};
