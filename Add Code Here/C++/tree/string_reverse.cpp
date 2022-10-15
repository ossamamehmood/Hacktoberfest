//Reversing the string words at their own place.
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{	clrscr();
	char str[5000],word[20],s;
	int i,k=0;
	cout<<"\n enter any string\n";	//Taking input in a character array str.
	gets(str);
	strcat(str," ");
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			word[k++]=str[i];	//checking for spaces and reversing each word at it's own place in sentence.
		}
		else
		{
			while(k>0)
			cout<<word[--k];
			cout<<' ';
		}
	}
	getch();
}

