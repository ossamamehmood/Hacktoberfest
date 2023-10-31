#include <stdio.h>
#include <stdbool.h>

// Function to check if there exists a subset with a given sum
bool isSubsetSum(int nums[], int n, int target) {
    // Create a 2D DP table
    bool dp[n + 1][target + 1];
    
    // Base case: If the target sum is 0, then there is always an empty subset.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            // If the current element (nums[i-1]) is greater than the target sum (j),
            // then we cannot include it in the subset, so the result is the same as
            // excluding this element.
            if (nums[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else {
                // Otherwise, we have two choices: include the current element or exclude it.
                // We use logical OR (||) to check if either choice is True.
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    
    // The final result is stored in dp[n][target]
    return dp[n][target];
}

int main() {
    int nums[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    if (isSubsetSum(nums, n, target))
        printf("Subset with the given sum exists.\n");
    else
        printf("No subset with the given sum exists.\n");
    
    return 0;
}
