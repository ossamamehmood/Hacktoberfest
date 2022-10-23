#include <bits/stdc++.h>
using namespace std;


int main()
{
 

long[,] d = new long[N + 1, maxWeight + 1];

for (long i = 0; i < N; i++)
{
	for (long w = 0; w <= maxWeight; w++)
	{                    
		if (weights[i] <= w)
		{
			// Exclude or include
			d[i + 1, w] = Math.Max(d[i, w], d[i, w - weights[i]] + values[i]);
		}

		else
		{
			// Exclude
			d[i + 1, w] = d[i, w];
		}                    
	}
}
   return 0;
}
 
