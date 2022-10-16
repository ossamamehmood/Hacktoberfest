#include <stdio.h>
void main()
{
    int a[100], j, i = 0, n, r;
    printf("enter the no in decimal equivalent");
    {
        scanf("%d", &n);
    }
    while (n != 0)
    {
        r = n % 2;
        a[i] = r;
        n = n / 2;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", a[j]);
    }
    // printf("binary equivalent is %d", a[j]);
}