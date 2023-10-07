#include <stdio.h>

int main()
{
    int B;
    printf("Enter the rows for Number Pyramid : ");
    scanf("%d", &B);
    for (int P = 1; P <= B; P++)
    {
        for (int R = 1; R <= (B - P); R++)
        {
            printf(" ");
        }
        for (int j = 1; j <= P; j++)
        {
            printf("%d ", P);
        }
        printf("\n");
    }
    return 0;
}