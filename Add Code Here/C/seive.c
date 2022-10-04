#include <stdio.h>

const int N = 1e7;
int Prime[10000000];

void Seive()
{
    for (int i = 0; i < N; i++)
        Prime[i] = 1;
    Prime[0] = Prime[1] = 0;
    for (int i = 2; i < N; i++)
        if (Prime[i])
            for (int j = 2 * i; j < N; j += i)
                Prime[j] = 0;
}

int main()
{
    int n;
    Seive();
    printf("Enter the number to check prime for\n");
    scanf("%d", &n);
    if (Prime[n])
        printf("The number is a prime no\n");
    else
        printf("The number is not a prime no\n");

    return 0;
}