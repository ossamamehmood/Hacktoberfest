#include <stdio.h>

int main()
{
    int B;
    printf("Enter the rows for the triangle : ");
    scanf("%d", &B);
    for (int P = 1; P <= B; P++)
    {
        for (int J = 1; J <= B - P; J++)
        {
            printf(" ");
        }
        for (int J = P; J >= 1; J--)
        {
            printf("%d", J);
        }
        for (int J = 2; J <= P; J++)
        {
            printf("%d", J);
        }
        printf("\n");
    }
    return 0;
}