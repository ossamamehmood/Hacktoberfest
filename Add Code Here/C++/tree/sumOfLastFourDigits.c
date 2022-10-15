#include <stdio.h>
void main()
{
    long long int a, b, c, d, e, f, g, h, i;
    printf("enter your 7 digit no=");
    scanf("%lld", &a);
    b = a % 10;
    c = a / 10;
    d = c % 10;
    e = c / 10;
    f = e % 10;
    g = e / 10;
    h = g % 10;
    i = h + f + d + b;
    printf("\n sum of last four digits entered by you"
           "%lld",
           i);
}