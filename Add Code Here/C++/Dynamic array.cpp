#include<stdio.h>
int main()
{
	int * ptr;
	ptr=new int[5];  // size of array = 5 // allocated bytes = 20 bytes
	for(int i=0;i<5;i++)
	{
		printf("Enter array element : ");
		scanf("%d",&ptr[i]);
	}
	printf("\n\nEntered array  : ");
	for(int i=0;i<5;i++)
	{
		printf("\t%d",ptr[i]);
	}
	delete[] ptr;
	printf("\n\n");
}
