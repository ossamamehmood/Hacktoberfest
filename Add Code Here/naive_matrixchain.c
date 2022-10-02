/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// place parenthesis at different places between first
	// and last matrix, recursively calculate count of
	// multiplications for each parenthesis placement and
	// return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver code
int main()
{
	//srand(time(0));
	FILE *fptr;
	fptr = fopen("naive_mchain.txt", "w");
	fprintf(fptr,"n,avg_time_take_ms\n");
	for (int n = 3; n <= 22; n++)
	{
		float sum=0.0000,avg=0.0000;
		for (int i = 0; i < 2; i++)
		{
			int a[n];
			for (int j = 0; j < n; j++)
			{
				a[j] = rand() % 10 + 1;
			}
			// printf("\nArray elements are : \n");
			// for (int j = 0; j < 6; j++)
			// {
			// 	printf("%d , ", a[j]);
			// }
			float start_time = clock();
			printf("\nMinimum number of multiplications is %d ",
				   MatrixChainOrder(a, 1, n - 1));
			printf("\n");
			float end_time = clock();
			sum=(end_time - start_time) * 1000 / CLOCKS_PER_SEC+sum;
			printf("n is %d Run %d: %0.4fms\n", n, i + 1, (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
		}
		avg=sum/2;
		fprintf(fptr,"%d,%0.4f\n",n,avg);
	}
	fclose(fptr);
	return 0;
}