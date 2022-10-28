public class leetcode1672 {
    public static void main(String[] args) {

        int [][] accounts = {{1,2,3},{4,5,5},{7,3,7}};
        System.out.println(maximumWealth(accounts));
    }
    static public int maximumWealth(int[][] accounts) {
        int ans = Integer.MIN_VALUE;
        for (int[] account : accounts) {
            int sum = 0;
            for (int i : account) {
                sum += i;
            }
            if (sum > ans) {
                ans = sum;
            }
        }
        return ans;
    }
}
