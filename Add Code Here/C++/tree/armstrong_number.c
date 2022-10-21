/* Which is Armstrong number?
Armstrong number is a number that is equal to the sum of cubes of its digits. For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.*/

#include<stdio.h>

void main()
{
    int num,t,sum=0,cube=1,r;
   
    printf("Enter number: ");
    scanf("%d", &num);
    t=num;
    while(num!=0){
        
        r = num%10;
        cube = r*r*r;
        num/=10;
        sum=sum+cube;
        
    }
    if(t==sum){
        printf("Armstrong Number");
    }
    else{
        printf("Not Armstrong Number");
    }
    }
