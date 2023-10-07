class Solution {
    public int longestCommonSubsequence(String text1, String text2) {

        int n1 = text1.length();
        int n2 = text2.length();



            int dp[][] = new int[n1+1][n2+1];

           
            for(int i=0; i<n1; i++){
                for(int j=0; j<n2; j++){
                    if(i == 0 || j == 0){
                        dp[i][j] = 0;
                    }
                }
            }

           

            for(int i=1; i<n1+1; i++){
                for(int j=1; j<n2+1; j++){

                    

                    if(text1.charAt(i-1) == text2.charAt(j-1)){
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }

                    

                    else{

                        int ans1 = dp[i-1][j];
                        int ans2 = dp[i][j-1];

                        dp[i][j] = Math.max(ans1, ans2);
 
                    }
                }
            }

            return dp[n1][n2];
        
    }
}
