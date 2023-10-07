//  Using Steam API
class Solution {
    public int maximumWealth(int[][] accounts) {
        int max = 0;
        for(int[] account: accounts){
            max = Math.max(max, Arrays.stream(account).sum());
        }
        return max;
    }
}

//  Using for loop
class Solution {
    public int maximumWealth(int[][] accounts) {
        int max = 0;
        
        for(int i = 0; i < accounts.length; i++){
            int sum = 0;
            for(int j = 0; j < accounts[i].length; j++){
                sum += accounts[i][j];
            }
            max = max > sum ? max : sum;
        }
        
        return max;
    }
}
