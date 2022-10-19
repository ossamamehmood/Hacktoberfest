

#include<stdio.h>
#include<math.h>
void prime(int m);
void main()
{
    int n;
    printf("Enter nth=");
    scanf("%d",&n);
    prime(n);
}
void prime(int n)
{
    int count=1,j,i,flag;
    if(n==1)
    {
	   	printf("prime no is 2 ");
	   	return;
	}
    for( j=3;j<=10000;j++)
    {
    	for(i=2,flag=0;i<=sqrt(j);i++)
    	{
	        if(j%i==0)
    	    {
        	    flag=1;
				break;
        	}
    	}
    	if(flag==0)
    	{
	        count++;
	    }
    	if(count==n)
    	{
	        printf("Prime number=%d\n",j);
    	   break;//since its within the j loop without the break statement 
    	          //it keeps printing up until the next prime number
	    }
    }
}
