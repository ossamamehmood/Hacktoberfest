#include <stdio.h>

int main() {
    int B;
    printf("Enter the rows for the butterfly : ");
    scanf("%d", &B);
    for (int P = 1; P <= B; P++) {
        for (int Q = 1; Q <= P; Q++) {
            printf("* ");
        }
        for (int R = 1; R <= 2 * (B - P); R++) {
            printf("  ");
        }
        for (int Q = 1; Q <= P; Q++) {
            printf(" *");
        }
        printf("\n");
    }
    for (int P = B; P >= 1; P--) {
        for (int Q = 1; Q <= P; Q++) {
            printf("* ");
        }
        for (int R = 1; R <= 2 * (B - P); R++) {
            printf("  ");
        }
        for (int Q = 1; Q <= P; Q++) {
            printf(" *");
        }
        printf("\n");
    }
    return 0;
}