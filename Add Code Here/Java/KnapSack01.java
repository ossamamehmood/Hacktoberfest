import java.util.Arrays;

public class KnapSack01{

    // Code Using only Recursion
    public static int knapSack(int val[],int wt[],int W,int n){ // Time Complexity : O(2^n)
        // Base Case
        if(n == 0 || W == 0){
            return 0;
        }

        if(wt[n-1] <= W){ // Valid case
            // Including self weight
            int ans1 = val[n-1] + knapSack(val, wt, W-wt[n-1], n-1);

            // Excluding self weight
            int ans2 = knapSack(val, wt, W, n-1);

            return Math.max(ans1,ans2);
        }else{ // Invalid
            return knapSack(val, wt, W, n-1);
        }
    }

    // Code Using Recursion + Memoization
    public static int knapSack(int val[],int wt[],int W,int n,int dp[][]){ // Time Complexity : O(n * W)
        // Base Case
        if(n == 0 || W == 0){
            return 0;
        }
        // if we already calculated the max profit for n items carry in knapsack of W weight then simply return it,no need to repeat again.
        if(dp[n][W] != -1){
            return dp[n][W];
        }

        if(wt[n-1] <= W){ // Valid
            // Including
            int ans1 = val[n-1] + knapSack(val, wt, W-wt[n-1], n-1,dp);
            // Excluding
            int ans2 = knapSack(val, wt, W, n-1,dp);

            dp[n][W] = Math.max(ans1, ans2);
            return dp[n][W];
        }else{ // Invalid
            dp[n][W] = knapSack(val, wt, W, n-1,dp);
            return dp[n][W];
        }
    }

    // Code Using Tabulation
    public static int knapSackTab(int wt[],int val[],int W){ // Time Complexity : O(n * W)
        int n = val.length;
        // Each cell is used to store maxProfit if we include i items in j size of knapsack
        int dp[][] = new int[n+1][W+1];
        // Initialize dp array
        // According to Base case in recursion when value of items(n) == 0 OR Knapsack capacity == 0 then maxProfit = 0;
        
        // Initialize 0th row 
        for(int i = 0; i < dp[0].length; i++){
            dp[0][i] = 0;
        }
        // Initialize 0th column 
        for(int i = 0; i < dp.length; i++){
            dp[i][0] = 0;
        }


        for(int i = 1; i <= n; i++){ // i means number of items
            for(int j = 1; j <= W; j++){ // j means knapsack capacity
                int v = val[i-1];
                int w = wt[i-1];

                // Valid case
                if(w <= j){
                    // Profit after including val,wt
                    int incProfit = v + dp[i-1][j-w];
                    // Profit after excluding val,wt
                    int excProfit = dp[i-1][j];
                    
                    dp[i][j] = Math.max(incProfit, excProfit);
                }else{ // Invalid case, then simply exclude val,wt
                    int excProfit = dp[i-1][j];
                    dp[i][j] = excProfit;
                }
            }
        }
        // print(dp);
        return dp[n][W]; // Here our answer for weight = W is stored,that we return to main.
    }
    // Utitlity to print DP array to verify process
    public static void print(int dp[][]){
        for (int[] row : dp) {
            for (int ele : row) {
                System.out.print(ele + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int val[] = {15,14,10,45,30};
        int wt[] = {2,5,1,3,4}; 
        int W = 7;
        System.out.println("MaxProfit Gain Using Recursion = " + knapSack(val, wt, W, val.length));


        // Using Memoization
        int dp[][] = new int[val.length+1][W+1];
        for(int i = 0; i < dp.length; i++){
            Arrays.fill(dp[i], -1);
        }
        System.out.println("MaxProfit Gain Using Memoization = " + knapSack(val, wt, W, val.length, dp));
        
        
        // Using Tabulation
        System.out.println("MaxProfit Gain Using Tabulation = " + knapSackTab(wt, val, W));
    }

}
