#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i=0,j,k,l;
	scanf("%[^\n]",str);
	l=strlen(str);
	while(str[i]!='\0')
	{
		while(str[j]!='\0')
		{
			while(str[k]!='\0')
			{
				if((str[i]!=str[j])&&(str[i]!=str[k])&&(str[k]!=str[j]))
					printf("%c%c%c\n",str[i],str[j],str[k]);
				k++;
			}
			j++;
			k=0;
		}
		j=0;
		i++;
	}
}
