#include<stdio.h>

int fib(int n) {
  static int fib_table[1005];
  if (n < 0) {
    return -1;
  } else if (n <= 1) {
    return n;
  } else if (fib_table[n] != -1) {
    return fib_table[n];
  } else {
    fib_table[n] = fib(n - 1) + fib(n - 2);
    return fib_table[n];
  }
}

void main()
{
	int i,j;
	printf("Enter number of elements in sequence:\n");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		printf("%d ",fib(j));
	}
	
}
