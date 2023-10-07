public class NoOfGP{
    public static void main(String[] args) {
        
    }

    class Solution {
        public int numIdenticalPairs(int[] nums) {
            int ans = 0;
            int count[] = new int[101];
    
            for(int n:nums)
            {
                count[n]++;
            } 
            for(int n:count)
            {
               ans+=(n*(n-1))/2; 
            }
            return ans;
        }
    }
}