class Solution {
    public int memoization(int i, int j, int[] nums1, int[] nums2, int[][]dp){
        if(i < 0 || j < 0){ 
            return -(int)1e9;
        }
        if(dp[i][j] != Integer.MIN_VALUE){ 
            return dp[i][j];
        }
        int take = Math.max(nums1[i] * nums2[j], nums1[i] * nums2[j] + memoization(i - 1, j - 1, nums1, nums2, dp));
        int notTake = Math.max(memoization(i - 1, j, nums1, nums2, dp), memoization(i, j - 1, nums1, nums2, dp));
        return dp[i][j] = Math.max(take, notTake);
    }
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int[][]dp = new int[nums1.length][nums2.length];
        for(int[] row : dp){
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        return memoization(nums1.length - 1, nums2.length - 1, nums1, nums2, dp);
    }
}
