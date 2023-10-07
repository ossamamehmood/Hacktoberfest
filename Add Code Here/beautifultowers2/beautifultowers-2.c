#include <stdio.h>

#define MAX_HEIGHT 100

long long int dp[MAX_HEIGHT][3];

long long int countBeautifulTowers(int n) {
    // Initialize the dynamic programming table
    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    // Fill the dynamic programming table
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
    }

    // Calculate the total number of beautiful towers of height n
    return dp[n][0] + dp[n][1] + dp[n][2];
}

int main() {
    int n;
    printf("Enter the height of the tower (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_HEIGHT) {
        printf("Invalid input. Height should be between 1 and %d.\n", MAX_HEIGHT);
        return 1;
    }

    long long int beautifulTowers = countBeautifulTowers(n);
    printf("Number of beautiful towers of height %d: %lld\n", n, beautifulTowers);

    return 0;
}
