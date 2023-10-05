public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        private static final int MOD = 1000000007;

        public int numMusicPlaylists(int n, int goal, int k) {
            long[][] temp = new long[goal + 1][n + 1];
            temp[0][0] = 1;

            for (int i = 1; i <= goal; i++) {
                for (int j = 1; j <= n; j++) {
                    temp[i][j] = (temp[i][j] + temp[i - 1][j - 1] * (n - j + 1)) % MOD;
                    if (j > k) {
                        temp[i][j] = (temp[i][j] + temp[i - 1][j] * (j - k)) % MOD;
                    }
                }
            }

            return (int) temp[goal][n];
        }
    }

}