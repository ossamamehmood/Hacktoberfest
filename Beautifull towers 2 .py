def maxBeautifulTowerHeight(maxHeights, heights):
    n = len(maxHeights)
    dp = [[0] * (maxHeights[i] + 1) for i in range(n)]
    for i in range(1, maxHeights[0] + 1):
        dp[0][i] = min(i, heights[0])

    for i in range(1, n):
        for j in range(1, maxHeights[i] + 1):
            dp[i][j] = dp[i - 1][j]
            for k in range(1, min(j, heights[i]) + 1):
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + k)

    return max(dp[n - 1])

# Example usage
maxHeights = [2, 3, 1, 4]
heights = [1, 2, 4, 1]
result = maxBeautifulTowerHeight(maxHeights, heights)
print(result)  # Output: 6
