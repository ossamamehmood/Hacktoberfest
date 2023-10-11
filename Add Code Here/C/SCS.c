//Script to find the Shortest COmmon Subsequence
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int shortestCommonSupersequenceLength(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

void printSCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int SCSLength = shortestCommonSupersequenceLength(X, Y);
    char SCS[SCSLength + 1];

    int i = m, j = n, k = SCSLength;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            SCS[k - 1] = X[i - 1];
            i--;
            j--;
            k--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            SCS[k - 1] = X[i - 1];
            i--;
            k--;
        } else {
            SCS[k - 1] = Y[j - 1];
            j--;
            k--;
        }
    }

    while (i > 0) {
        SCS[k - 1] = X[i - 1];
        i--;
        k--;
    }

    while (j > 0) {
        SCS[k - 1] = Y[j - 1];
        j--;
        k--;
    }

    SCS[SCSLength] = '\0';

    printf("Shortest Common Supersequence: %s\n", SCS);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    int SCSLength = shortestCommonSupersequenceLength(X, Y);
    printf("Length of Shortest Common Supersequence: %d\n", SCSLength);

    printSCS(X, Y);

    return 0;
}
