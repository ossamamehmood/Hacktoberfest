class Solution {
	public String longestPalindrome(String s) {
		boolean dp[][] = new boolean[s.length()][s.length()];
		int count = Integer.MIN_VALUE;
		String ans = "";
		for (int g = 0; g < s.length(); g++) {
			for (int i = 0, j = g; j < s.length(); j++, i++) {
				if (g == 0)
					dp[i][j] = true;
				else if (g == 1) {
					if (s.charAt(i) == s.charAt(j))
						dp[i][j] = true;
				}
				// the number of gaps is more than two
				else {
					if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1])
						dp[i][j] = true;
				}
				if (dp[i][j]) {
					// if(j-i+1>count){
					// count=j-i+1;
					// ans=s.substring(i,j+1);

					ans = s.substring(i, j + 1);// works for all the palindromic substrings and the last
					// case is the longest palindromic substring
				}
			}
		}
		return ans;
	}

}
