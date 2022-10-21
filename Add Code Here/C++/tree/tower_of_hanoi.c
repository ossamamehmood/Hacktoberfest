#include<stdio.h>
void towerOfHanoi(int d,char T1,char T2,char T3)
{
	if(d==1){
		printf("\nmove disk from %c to %c ",T1,T2);
		return;
	}
	towerOfHanoi(d-1,T1,T3,T2);
	printf("\nmove disk from %c to %c",T1,T2);
	towerOfHanoi(d-1,T3,T2,T1);
	
}

int main(){
	int rings;
	printf("enter the number of rings : ");
	scanf("%d",&rings);
	towerOfHanoi(rings,'A','C','B');
	return 0;
}
