#include <stdio.h>

int main() {
    int B;
    printf("Enter the rows for the pyramid : ");
    scanf("%d", &B);
    for (int P = 1; P <= B; P++) {
        for (int Q = 1; Q <= B - P; Q++) {
            printf(" ");
        }
        for (int R = 1; R <= P; R++) {
            printf("%d ", R);
        }
        printf("\n");
    }
    return 0;
}