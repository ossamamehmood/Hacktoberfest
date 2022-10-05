class Solution {
public:
    int msd(vector<int> &v,int left,int right )
    {
        int mid=(left+right)/2;
        
        if(left==right)
            return v[left];
        int leftans=msd(v,left,mid);
        int rightans=msd(v,mid+1,right);
        int temp=0;
        int leftmax=v[mid];
        int rightmax=v[mid+1];
        for(int i=mid;i>=left;i--)
        {
            temp+=v[i];
            if(temp>leftmax)
                leftmax=temp;
            
        }
        temp=0;
     for(int i=mid+1;i<=right;i++)
        {
            temp+=v[i];
            if(temp>rightmax)
                rightmax=temp;
            
        }
       return max((leftans,rightans),leftmax+rightmax);
        
        
        
    }
    int maxSubArray(vector<int>& nums) {
        return msd(nums,0,nums.size()-1);
        
        
    }
};
