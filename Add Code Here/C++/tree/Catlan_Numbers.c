// by Sushant Gaurav (@imsushant12)

#include<stdio.h>

//Time Complexity: O(4^n)
int catalan(int n)
{
    int result=0;

    if(n <= 1)
        return 1;

    for(int i=0 ; i<n ; i++)
        result += catalan(i)*catalan(n-i-1);

    return result;
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("\nRequired Catalan Number = %d.\n",catalan(n));

    printf("\nCatalan Series formed: ");
    for(int i=0 ; i<=n ; i++)
        printf("%d  ",catalan(i));

    return 0;
}
