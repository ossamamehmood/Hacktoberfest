#include<stdio.h>


void main()
{
    int n,i,j;
    printf("\nenter the range of the pattern you want to print:");
    scanf("%d", &n);


    printf("\n\n The pattern that will be displayed is:\n");
    int len = n*2 - 1;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++){
            int min = i < j ? i : j;
            min = min < len-i ? min : len-i-1;
            min = min < len-j-1 ? min : len-j-1;
            printf("%d ", n-min);
        }
        printf("\n");
    }
}
