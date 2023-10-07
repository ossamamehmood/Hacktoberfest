#include <stdio.h>

int main()
{
    int B;
    printf("Enter the rows for the rhombus : ");
    scanf("%d", &B);
    for (int P = 1; P <= B; P++)
    {
        for (int R = 1; R <= 2 * (B - P); R++)
        {
            printf("  ");
        }
        printf("* * * * * *\n");
    }
    return 0;
}