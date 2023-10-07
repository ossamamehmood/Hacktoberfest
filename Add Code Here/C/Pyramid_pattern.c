#include <stdio.h>

int main() {
    int n;
    
    // Input the number of rows for the pyramid pattern
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    // Loop for each row
    for (int i = 1; i <= n; i++) {
        // Print spaces for alignment
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        // Loop for printing asterisks
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        // Move to the next line after each row
        printf("\n");
    }
    
    return 0;
}
