class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, h = n;
        while (l<=h) {
            int partition1 = l + (h - l)/2;
            int partition2 = - partition1 + (m + n + 1)/2;
            
            int l1 = partition1 > 0 ? nums1[partition1-1] : INT_MIN;
            int l2 = partition2 > 0 ? nums2[partition2-1] : INT_MIN;
            int h1 = partition1 < n ? nums1[partition1] : INT_MAX;
            int h2 = partition2 < m ? nums2[partition2] : INT_MAX;
            
            if(l1<=h2 && l2<=h1) {
                if((m+n)%2) return max(l1, l2);
                else return (max(l1, l2)/2.0) + (min(h1, h2)/2.0);
            }
            else if(l1>h2) h = partition1 - 1;
            else l = partition1 + 1;
        }
        return 0.0;
    }
};
