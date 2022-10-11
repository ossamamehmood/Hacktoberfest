//Implemention of Banker's Safety and Request Algorithm
#include <stdio.h>
int main()
{
	// 5 Procesess: P0,P1,P2,P3 and P4

	int n, r, i, j, k;
	n = 5; // Number of processes
	r = 3; // Number of resources
	int alloc[5][3] = { { 1, 1, 2 }, 
						{ 2, 1, 3 }, 
						{ 4, 0, 1 }, 
						{ 0, 2, 1 }, 
						{ 1, 3, 2 } }; 

	int req[5][3] = { { 6, 2, 1 }, 
					{ 7, 4, 5 }, 
					{ 2, 1, 0 }, 
					{ 8, 5, 5 }, 
					{ 3, 0, 3 } }; 

	int avail[3] = { 3, 3, 2 }; // Available Resources

	int f[n], ans[n], pos = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][r];
	for (i = 0; i < n; i++) {
		for (j = 0; j < r; j++)
			need[i][j] = req[i][j] - alloc[i][j];
	}
	
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < r; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[pos++] = i;
					for (j = 0; j < r; j++)
						avail[j] += alloc[i][j];
					f[i] = 1;
				}
			}
		}
	}

	printf("The Safe Sequence is given below:-\n");
	for (i = 0; i < n - 1; i++)
		printf("P%d--> ", ans[i]);
	printf("P%d", ans[n - 1]);

	return 0;

}

