public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int strangePrinter(String s) {
            int n = s.length();
            int[][] temp = new int[n][n];
            return minTurns(s, 0, n - 1, temp);
        }

        int minTurns(String s, int start, int end, int[][] temp) {
            if (start > end) {
                return 0;
            }

            if (temp[start][end] > 0) {
                return temp[start][end];
            }

            int turns = minTurns(s, start, end - 1, temp) + 1;
            for (int i = start; i < end; i++) {
                if (s.charAt(i) == s.charAt(end)) {
                    turns = Math.min(turns, minTurns(s, start, i, temp) + minTurns(s, i + 1, end - 1, temp));
                }
            }

            temp[start][end] = turns;
            return turns;
        }
    }

}