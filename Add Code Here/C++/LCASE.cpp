#include<stdio.h>
int main()
{
	char str[100],i=0;
	scanf("%[^\n]",str);
	while(str[i]!='\0')
	{
		if(str[i]>=65&&str[i]<=90)
		{
		str[i]=str[i]+32;
		i++;
	    }
	    else if(str[i]>=97&&str[i]<=122)
	    {
		//str[i]=str[i]-32;
		i++;
	    }
	    else
	    {
	    	i++;
		}
	}
	printf("\n%s",str);
}
