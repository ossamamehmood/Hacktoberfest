#include<stdio.h>

void towers(int,char,char,char);

int main()
{
	int num;
	printf("\nEnter The Number Of Disks : ");
	scanf("%d",&num);
	printf("\nThe Sequence Of Moves Involved in the Tower of Hanoi are : ");
	towers(num,'A','C','B');
	return 0;
}


void towers(int num,char frompeg,char topeg,char auxpeg)
{
	if(num==1)
	{
		printf("\n Move Disk 1 From Peg %c To %c",frompeg,topeg);
		return;
	}
	towers(num-1,frompeg,auxpeg,topeg);
	printf("\n Move Disk %d from peg %c to %c",num,frompeg,topeg);
	towers(num-1,auxpeg,topeg,frompeg);
}
