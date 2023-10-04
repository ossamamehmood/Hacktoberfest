#include<stdio.h>


// 1. Brute force
// 2. Recursive Approach


int function(int a,int b,int n){
    if(b==1){
        return a%n;
    }
    if(b%2==0){
        return (function(a,b/2,n)*function(a,b/2,n))%n;
    }else{
        return (function(a,b/2,n)*function(a,b/2,n)*a)%n;
    }
}


int bruteForceModExp(int a, int b, int n) {
    int result = 1;

    for (int i = 0; i < b; i++) {
        result = (result * a) % n;
    }

    return result;
}



int main(){
    printf("Enter base: ");
    int a;
    scanf("%d",&a);
    printf("Enter exponent: ");
    int b;
    scanf("%d",&b);
    printf("Enter the modulo number: ");
    int n;
    scanf("%d",&n);
    printf("%d",bruteForceModExp(a,b,n));


    return 0;
}
