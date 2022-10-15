#include <stdio.h>

main()
{
    int *px, y;
    px = &y;

    printf("\n Enter Your Value = ");
    scanf("%d", &y);
    printf(" Your Value %d \n", *px);
}
