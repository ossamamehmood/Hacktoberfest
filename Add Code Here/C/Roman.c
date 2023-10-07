#include<stdio.h> 
int main(){ 
    int num,remainder; 
    scanf("%d",&num); 
    for(int i=1;i<=num/1000;i++)
    printf("M");

    num=num%1000;

    for(int i=1;i<=num/900;i++)
    printf("CM");

    num=num%900;

    for(int i=1;i<=num/500;i++)
    printf("D");

    num=num%500;

    for(int i=1;i<=num/400;i++)
    printf("CD");

    num=num%400;

    for(int i=1;i<=num/100;i++)
    printf("C");
    
    num=num%100;

    for(int i=1;i<=num/90;i++)
    printf("XC");
    
    num=num%90;

    for(int i=1;i<=num/50;i++)
    printf("L");
    
    num=num%50;

    for(int i=1;i<=num/40;i++)
    printf("XL");
    
    num=num%40;

    for(int i=1;i<=num/10;i++)
    printf("X");
    
    num=num%10;

    for(int i=1;i<=num/9;i++)
    printf("IX");
    
    num=num%9;

    for(int i=1;i<=num/5;i++)
    printf("V");
    
    num=num%5;

    for(int i=1;i<=num/4;i++)
    printf("IV");
    
    num=num%4;

    for(int i=1;i<=num;i++)
    printf("I");
}