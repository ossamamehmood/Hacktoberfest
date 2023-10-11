//Script to find the largest common subsequence
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];

    // Build the LCS matrix
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Find the LCS length
    int length = L[m][n];

    // Create an array to store the LCS
    char lcs[length + 1];
    lcs[length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
