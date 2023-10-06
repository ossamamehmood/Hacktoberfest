#include <stdio.h>

int main() {
    int i, j, rows;

    // Input the number of rows for the rhombus
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Loop to print the upper part of the rhombus
    for (i = 1; i <= rows; i++) {
        // Print leading spaces
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Print stars
        for (j = 1; j <= rows; j++) {
            printf("*");
        }

        // Move to the next line after each row is printed
        printf("\n");
    }

    // Loop to print the lower part of the rhombus
    for (i = 1; i <= rows; i++) {
        // Print leading spaces
        for (j = 1; j < i; j++) {
            printf(" ");
        }

        // Print stars
        for (j = 1; j <= rows; j++) {
            printf("*");
        }

        // Move to the next line after each row is printed
        printf("\n");
    }

    return 0;
}
