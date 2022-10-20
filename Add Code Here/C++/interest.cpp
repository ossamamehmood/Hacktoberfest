#include<stdio.h>
//calculate the simple interest and final amount
int main(){
	float principal;
	float rate;
	float tenure ;
	
	printf("enter principal  ");
	scanf("%f",&principal );
	
	printf("enter rate ");
	scanf("%f",&rate);
	
	printf("enter tenure ");
	scanf("%f",&tenure);
	
	printf("Simple Interest = %f \n",principal  * tenure * rate * 0.01);

	printf(" Final = %f \n ",principal + principal*rate*tenure*0.01);
	

	
	return 0;
	
	
}