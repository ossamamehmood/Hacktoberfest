#include <bits/stdc++.h>
using namespace std;

void percolate_down(int numbers[], int i, int n)
{
	int smallest = i;
	int left  = 2*i+1;
	int right  = 2*i+2;
	if(left<n && numbers[left]<numbers[smallest]) smallest = left;
	if(right<n && numbers[right]<numbers[smallest]) smallest = right;
	if(smallest!=i)
	{
		swap(numbers[i], numbers[smallest]);
		percolate_down(numbers, smallest, n);
	}
}

void buildHeap(int numbers[], int n)
{
	int last_parent = (n-2)/2;
	while(last_parent>=0)
	{
		percolate_down(numbers, last_parent, n);
		last_parent--;
	}
}

int extractMin(int A[], int n)
{
	int ans = A[0];
	swap(A[n-1], A[0]);
	n = n-1;
	percolate_down(A, 0, n);
	return ans;

}

void heapSort(int numbers[], int len)
{
	//build a heap from the given array
	int T[len];	
	buildHeap(numbers, len);
	int n=len;
	for(int i=0; i<n; i++)
	{
		T[i] = extractMin(numbers, len);
		len--;

	}
	for(int i=0; i<n;i++)
	{
		numbers[i] = T[i];
	}

}

void print_heap(int numbers[], int n)
{
	cout<<"heap is --> ";
	for(int i=0; i<n; i++)
	{
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
}



int main()
{
	int numbers[] = {14, 6, 7, 34, 56, 213, 892, 765, 45, 23, 76, 11, 1, 2, 3, 67};
	int len = sizeof(numbers)/sizeof(numbers[0]);
	// buildHeap(numbers, len);
	heapSort(numbers, len);
	
	print_heap(numbers, len);
	return 0;
}