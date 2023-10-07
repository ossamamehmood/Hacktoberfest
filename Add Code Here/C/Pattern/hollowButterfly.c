#include <stdio.h>

int main() {
    int B;
    printf("Enter the rows for the Butterfly : ");
    scanf("%d", &B);
    
    for (int P = 1; P <= B; P++) {
        for (int R = 1; R <= P; R++) {
            if (P == 1 || R == 1 || P == 2 * B || R == 2 * B) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        for (int Q = 1; Q <= 2 * (B - P); Q++) {
            printf("   ");
        }
        for (int R = 1; R <= P; R++) {
            if (P == 1 || R == 1 || P == 2 * B || R == 2 * B) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    
    for (int P = B; P >= 1; P--) {
        for (int Q = 1; Q <= P; Q++) {
            if (P == 1 || Q == 1 || P == 2 * B || Q == 2 * B) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        for (int R = 1; R <= 2 * (B - P); R++) {
            printf("   ");
        }
        for (int Q = 1; Q <= P; Q++) {
            if (P == 1 || Q == 1 || P == 2 * B || Q == 2 * B) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    
    return 0;
}