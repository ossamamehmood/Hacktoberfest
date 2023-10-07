#include <stdio.h>

int main() {
    int n;
    
    // Input the number of rows for the inverted right triangle pattern
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    // Loop for each row in reverse order
    for (int i = n; i >= 1; i--) {
        // Loop for each column in the current row
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        // Move to the next line after each row
        printf("\n");
    }
    
    return 0;
}
