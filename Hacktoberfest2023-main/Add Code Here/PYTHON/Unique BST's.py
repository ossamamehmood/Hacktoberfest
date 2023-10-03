class Solution:
    # Function to return the total number of possible unique BSTs.
    def numTrees(self, N):
        if N <= 1:
            return 1

        # Create a list to store the number of unique BSTs for each number from 0 to N.
        dp = [0] * (N + 1)
        dp[0] = dp[1] = 1

        # Calculate the number of unique BSTs for each number from 2 to N.
        for i in range(2, N + 1):
            for j in range(1, i + 1):
                dp[i] += dp[j - 1] * dp[i - j]

        return dp[N]

# Example usage:
sol = Solution()
N = 2
print(sol.numTrees(N))  # Output: 2
