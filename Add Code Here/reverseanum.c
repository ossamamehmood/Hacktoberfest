#include <stdio.h> 

int main()
{   
    int n, a;
    printf("Enter the Number which you want to reverse\n");
    scanf("%d", &n);
    a = n - (n/10)*10;
    printf("Reversed Number:- %d", a);
    return 0;
}