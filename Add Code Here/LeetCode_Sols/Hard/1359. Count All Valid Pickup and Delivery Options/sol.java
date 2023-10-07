public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    public class Solution {
        private static final int MOD = 1000000007;

        public int countOrders(int n) {
            long count = 1;
            for (int i = 2; i <= n; i++) {
                count = (count * (2 * i - 1) * i) % MOD;
            }
            return (int) count;
        }
    }
}