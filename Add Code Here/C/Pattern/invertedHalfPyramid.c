#include <stdio.h>

int main()
{
    int B, C = 1;
    printf("Enter the rows for the pyramid : ");
    scanf("%d", &B);
    for (int P = B; P >= 1; P--)
    {
        for (int Q = 1; Q <= B - P; Q++)
        {
            printf(" ");
        }
        for (int R = 1; R <= P; R++)
        {
            printf("%d ", C);
        }
        printf("\n");
        C++;
    }
    return 0;
}