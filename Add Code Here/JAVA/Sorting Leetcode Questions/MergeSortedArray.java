class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
         int i1 = m - 1;  
         int i2 = n - 1; 
         
         
         while (i1 >= 0 && i2 >= 0) {
             if (nums1[i1] >= nums2[i2]) {
                 nums1[i1 + i2 + 1] = nums1[i1--];
             } else {
                 nums1[i1 + i2 + 1] = nums2[i2--];
             }
         }
         
         while (i2 >= 0) {
             nums1[i2] = nums2[i2--];
         }
     }
 }
