#include <stdio.h>

int main() {
    int n;
    
    // Input the number of rows for the right triangle pattern
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    // Loop for each row
    for (int i = 1; i <= n; i++) {
        // Loop for each column in the current row
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        // Move to the next line after each row
        printf("\n");
    }
    
    return 0;
}
