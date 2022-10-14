public class Solution {
    public int wordBreak(String A, String[] B) {
        Set<String> set = new HashSet<>();
        for (String s : B) {
            set.add(s);
        }
        Boolean[] dp = new Boolean[A.length()];
        return wordBreak(A, set, 0, dp);
    }
    
    private int wordBreak(String s, Set<String> set, int start, Boolean[] dp) {
        if (start == s.length()) {
            return 1;
        }
        if (dp[start] != null) return dp[start] ? 1 : 0;
        
        int ans = 0;
        for (int end = start + 1; end <= s.length(); end++) {
            if (set.contains(s.substring(start, end)) && wordBreak(s, set, end, dp) == 1) {
                ans = 1;
                break;
            }
        }
        
        dp[start] = ans == 1;
        return ans;
    }
}

