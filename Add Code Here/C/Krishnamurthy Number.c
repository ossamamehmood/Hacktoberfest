#include<stdio.h>
int main()
{
	int n,temp,fact,sum=0,i,rem;
	printf("ENTER A NUMBER: ");
	scanf("%d",&n);
	temp=n;
	while(n!=0)
	{
		rem=n%10;
		fact=1;
		for(i=rem;i>=1;i--)
  		{	
   			fact=fact*i;
  		}
  		sum=sum+fact;
  		n=n/10;
 	}
 	if(sum==temp)
  		printf("%d IS A KRISHNAMURTY NUMBER\n",temp);
 	else
  		printf("%d IS NOT A KRISHNAMURTY NUMBER\n",temp);
 	return 0;
}