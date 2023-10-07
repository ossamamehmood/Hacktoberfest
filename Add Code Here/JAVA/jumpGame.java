 public static int jumpGame(int[] nums) {
        int len = nums.length;
        if (len <= 1) {
            return 0;
        }

        int[] dp = new int[len];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        int minStep = Integer.MAX_VALUE;
        for (int i = 0; i < len; i++) {
            int num = nums[i];
            for (int j = 1; j <= num && i + j < len; j++) {
                dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
                if (i + j >= len - 1) {
                    minStep = Math.min(minStep, dp[i] + 1);
                    return minStep;
                }
            }
        }

        return minStep;
    }
