#include<stdio.h>
int power(int b,int e)
{
	if(e==0)
		return 1;
	else
	 	return b*power(b,e-1);
}
int main()
{
	int b,e,res;
	scanf("%d %d",&b,&e);
	res=power(b,e);
	printf("ans :%d",res);
}
