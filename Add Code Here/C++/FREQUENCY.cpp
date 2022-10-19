#include<stdio.h>
int main()
{
	char str[100];
	int i,a,x,y,j;
	scanf("%[^\n]",str);
	for(i=0;str[i]!='\0';i++)
	{
		a=0;
		for(j=0;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
				a++;
		}
		x=0;
		y=i;
		while(x<y+1)
		{
			if(str[y]==str[x])
			{
				if(x==y)
					printf("\nfrequency of %c is %d",str[i],a);
				break;
			}
			else
			{
				x++;
			}
		}
	}
		
}
