#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the LCS of two strings
void findLCS(char *X, char *Y, int m, int n) {
    int LCS[m + 1][n + 1];
    int i, j;

    // Build the LCS matrix
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // Find the LCS and store it in lcs[]
    int index = LCS[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    findLCS(X, Y, m, n);

    return 0;
}
