class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> op;
        int prod =1;
        int is_zero = 0;
        for(auto it: nums){
            if(it!=0)
                prod *= it;
            else
                is_zero ++;
        }

        for(auto it: nums){
            if(it==0){
                if(is_zero >1) op.push_back(0);
                else op.push_back(prod);
            }else if(it!=0 && is_zero!=0){
                op.push_back(0);
            }else{
                op.push_back(prod/it);
            }
        }

        return op;
    }
};
