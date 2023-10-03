def maxSumOfHeights(heights, maxHeights):
n = len(heights)


dp = [[0, 0] for _ in range(n)]


dp[0][0] = heights[0]  
dp[0][1] = 0           


for i in range(1, n):
    
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + heights[i]
    
    
    dp[i][1] = max(dp[i-1][0] - maxHeights[i-1], dp[i-1][1])


return max(dp[n-1][0], dp[n-1][1])
heights = [1, 3, 5, 2, 4]
maxHeights = [2, 1, 7, 5, 6]
result = maxSumOfHeights(heights, maxHeights)
print(result)