public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public long maxRunTime(int n, int[] batteries) {
            long sum = 0;
            for (int x : batteries) {
                sum += x;
            }

            long stTime = 0;
            long endTime = sum;
            long ans = 0;

            while (stTime <= endTime) {
                long avg = (stTime + endTime) / 2;
                if (runFeasible(n, batteries, avg)) {
                    ans = avg;
                    stTime = avg + 1;
                } else {
                    endTime = avg - 1;
                }
            }
            return ans;
        }

        public boolean runFeasible(int n, int[] batteries, long avg) {
            long time = 0;
            for (int x : batteries) {
                if (x <= avg) {
                    time += x;
                } else {
                    time += avg;
                }
            }
            return time >= avg * n;
        }
    }

}