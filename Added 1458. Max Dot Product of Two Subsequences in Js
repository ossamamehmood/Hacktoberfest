/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDotProduct = function(nums1, nums2) {
    var m = nums1.length;
    var n = nums2.length;
    if (!m || !n) return 0;
    var dp = [[nums1[0] * nums2[0]]];
    for (var i = 1; i < m; i++) {
        dp[i] = [];
        dp[i][0] = Math.max(nums1[i] * nums2[0], dp[i-1][0]);
    }
    for (var i = 1; i < n; i++) dp[0][i] = Math.max(nums1[0] * nums2[i], dp[0][i-1]);
    for (var i = 1; i < m; i++) {
        for (var j = 1; j < n; j++) {
            var val = nums1[i] * nums2[j];
            dp[i][j] = Math.max(val, val + dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m - 1][n - 1];
};
