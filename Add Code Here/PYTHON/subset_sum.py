def isSubsetSum(nums, target):
    n = len(nums)
    
    # Create a 2D DP table, where dp[i][j] is True if there is a subset
    # of the first i elements of nums that has a sum of j.
    dp = [[False for _ in range(target + 1)] for _ in range(n + 1)]
    
    # Base case: If the target sum is 0, then there is always an empty subset.
    for i in range(n + 1):
        dp[i][0] = True
    
    # Fill the DP table
    for i in range(1, n + 1):
        for j in range(1, target + 1):
            # If the current element (nums[i-1]) is greater than the target sum (j),
            # then we cannot include it in the subset, so the result is the same as
            # excluding this element.
            if nums[i - 1] > j:
                dp[i][j] = dp[i - 1][j]
            else:
                # Otherwise, we have two choices: include the current element or exclude it.
                # We use logical OR (||) to check if either choice is True.
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]]
    
    # The final result is stored in dp[n][target]
    return dp[n][target]

# Example usage
nums = [3, 34, 4, 12, 5, 2]
target = 9
print(isSubsetSum(nums, target))  # Output: True (subset [3, 4, 2] sums to 9)
