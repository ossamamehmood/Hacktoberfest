#include <stdio.h>
#include <string.h>

int findMatches(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int flag = -1;
    int shiftCount = 0; // Initialize shift count

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            flag = 1;
        } else {
            shiftCount++; // Increment shift count for each valid shift
        }
    }

    printf("Total shifts performed: %d\n", shiftCount); // Print the total number of shifts
    return flag;
}

int main(int argc, char **argv) {
    char st[100], pat[100];
    int status;
    printf("*** Naive String Matching Algorithm ***\n");
    printf("Enter the String.\n");
    gets(st);
    printf("Enter the pattern to match.\n");
    gets(pat);

    int ans = findMatches(st, pat);
    if (ans == -1) {
        printf("String match not found\n");
    }
    return 0;
}

 