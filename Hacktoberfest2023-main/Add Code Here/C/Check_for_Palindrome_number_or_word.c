#include<stdio.h>
#include<string.h>
#include<conio.h>
int numi();
void stri();
int main()
{
	int a;
	printf("\n Is the input number or string(1-Number/2-String):");
	scanf("%d",&a);
	if(a==1)
	{
		numi();
	}
	else if(a==2)
	{
		stri();
	}
	return 0;
}

int numi()
{
	int num,rev_num=0,rem,temp;
	printf("Enter an integer: ");
	scanf("%d", &num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		rev_num=rev_num*10+rem;
		temp/=10;
	}

	if(rev_num==num)
	{
		printf("%d is a palindrome number",num);
	}
	else
	{
		printf("%d is not a palindrome number",num);
	}
	return 0;
}

void stri()
{
	char arr[40];
	int i,length;
	int f=0;

	printf("Enter a string:");
	scanf("%s",arr);
	length=strlen(arr);
	for(i=0;i<length;i++)
	{
		if(arr[i]!=arr[length-i-1])
		{
			f=1;
			break;
		}
	}

	if(f)
	{
		printf("%s is not a palindrome",arr);
	}
	else
	{
		printf("%s is a palindrome",arr);
	}
	getch();
}
