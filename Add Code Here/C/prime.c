//Write a complete C program to print prime numbers within a given range.
#include<stdio.h>
int main()
{
		int num,flag=0,j=2;
		printf("Enter the number:");
		scanf("%d", &num);
		if(num<=1)
		{
		printf("%d is not a prime number", num);
		}
				
		while(j<(num/2)+1)
		{
		if(num%j==0)
		{
		flag++;}
		j=j+1;
			}
		if(flag==0)
		{
		printf("%d is prime number", num);}
		else{
		printf("%d is  not prime number", num);
		}
		

    return 0;
}
