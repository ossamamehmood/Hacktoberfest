
#include <stdio.h>

int main()
{
    int n,i=0,rem,dec=0;
    printf("enter a binary no.");
scanf("%d",&n);
while(n!=0){
    rem=n%10;
    n=n/10;
    dec=dec+rem*pow(2,i);
    i++;
}
    printf("the decimal no. is %d",dec);
    return 0; 
}
