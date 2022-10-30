#include<stdio.h>
int reverse(int);
int main()
{
	int n;
	printf("Enter any integer");
	scanf("%d",&n);
	printf("\nReversed no. is %d",reverse(n));
    return 0;
}
int reverse(int a)
	 {  int rem, rev=0;
	    while(a!=0)
		{
		rem = a%10;
		rev = rev* 10 + rem;
        reverse(a=a/10);
		}
	    return rev;
	}
