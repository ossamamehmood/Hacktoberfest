#include <stdio.h>
long long int factorial (long long int n){
        if(n<0)
            return 0;
        if(n==0) 
            return 1;
        else
            return n*factorial(n-1);
    }

int main () {
    long long int n, total;
    scanf ("%lld", &n);
    total = factorial(n);
    printf ("%d\n", total);
    return 0;
}
