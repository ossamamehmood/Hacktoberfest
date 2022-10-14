class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s=3010;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1, h=n-1;
            while(l<h)
            {
                int p=nums[i];
                p+=nums[l];
                p+=nums[h];
                if(abs(s-target)>abs(p-target))
                {
                    s=p;
                }
                if(target>p) l++;
                else if(target<p) h--;
                else l++,h--;
            }
        }
        return s;
    }
};
