class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
      int n = nums1.size();
      int m = nums2.size();
      if(n > m )
          return findMedianSortedArrays(nums2,nums1);
        int low = 0 ; 
        int high = n ; 
        while(low <= high)
        {
            int divx = low + (high-low)/2;
            int divy = (n + m + 1)/2 - divx;
            
            int maxleft_x  = divx == 0 ? -1e9 : nums1[divx - 1];
            int minright_x = divx == n ? 1e9 : nums1[divx ];
            
            int maxleft_y  = divy == 0 ? -1e9 : nums2[divy - 1];
            int minright_y = divy == m ? 1e9 : nums2[divy ];
            
            if(maxleft_x <= minright_y && maxleft_y <= minright_x)
            {
                if( (n + m) %2 == 0)
                    return (double)(max(maxleft_y, maxleft_x) + min(minright_y , minright_x))/2;
                return (double)max(maxleft_y, maxleft_x);
            }
            if(maxleft_x > minright_y)
                high = divx-1;
            else
                low = divx + 1;
        }
        return 0;
    }
};