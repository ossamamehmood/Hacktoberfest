#include <stdio.h> 

int main()
{ 
    int n;
    printf("Enter number\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("O");
        }
        printf("\n");
    }
    
    return 0;
}