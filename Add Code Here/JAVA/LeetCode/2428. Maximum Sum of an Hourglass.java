// https://leetcode.com/problems/maximum-sum-of-an-hourglass/
/*
Time Complexity:O(n^2)
Space Complexity:O(1)
*/
class Solution {
    public int maxSum(int[][] g) {
       
        int ans=Integer.MIN_VALUE;
         for(int i=0;i<g.length-2;i++)
         {
             for(int j=0;j<g[0].length-2;j++)
             {
                 ans=Math.max(ans,g[i+0][j+0]+g[i+0][j+1]+g[i+0][j+2]+g[i+1][j+1]+g[i+2][j+0]+g[i+2][j+1]+g[i+2][j+2]);
                     
             }
         }
        return ans;
    }
}
