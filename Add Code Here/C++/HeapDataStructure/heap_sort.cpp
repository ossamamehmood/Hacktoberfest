// C++ Implementation of Heap Sort using Heapify Algorithm
#include<bits/stdc++.h>
using namespace std;

// Function to swap two given numbers passed by reference, will be utilized in the heapify and heap_sort functions.
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

/*
	Array representation of a binary tree : 
	[a,b,c,d] : 
	
			a
		   / \
		  b   c
		 /  
		d   
		
	The above tree is an example of a COMPLETE BINARY TREE, which is a binary tree that satisfies the following properties:
	--> All the leaf elements must lean towards the left.
	--> The last leaf element might not have a right sibling i.e it doesn't have to be a full binary tree. 
*/

/*
	Heapify Function to build a max-heap from a given tree.
	A max-heap is a COMPLETE BINARY TREE, in which all its nodes satisfy the property that they are greater than their children.
*/
void heapify(vector<int> &vals, int n){
	/*
		- To build a max-heap, we should heapify each sub-tree from the bottom up and end up with a max-heap after the function 
		  is applied to all elements, including the root element.
		- The first index of a non-leaf node (in a bottom-up approach) is given by (n/2 - 1) where n is the number of nodes in the tree. 
	*/
	for(int i=n/2;i>=1;--i){
		// For an element at index i, the element at index 2*i will become the left child 
		// and the element at index (2*i + 1) will become the right child. 
		if(2*i<n && vals[2*i-1] < vals[2*i]){
			// If element at right child is greater, then it is swapped with the parent.
			if(vals[2*i] > vals[i-1]) swap(vals[2*i],vals[i-1]);
		}
		else{
			// If element at left child is greater, then it is swapped with the parent.
			if(vals[2*i-1] > vals[i-1]) swap(vals[2*i-1],vals[i-1]);
		}
		// In this manner, the largest element is brought to the root of the tree. 
	}
}

/*
	Function to carry out Heap Sort algorithm to a given vector, passed by reference. 
	
	Time Complexity - O(N * log N)
	Space Complexity - O(1)
*/

void heap_sort(vector<int> &vals){
	int sze = (int)vals.size();
	for(int i=sze;i>=1;--i){
		/* 
			- For every iteration of the heapify algorithm, the largest element of the array is obtained. 
			- This value is then swapped with the last item of the array, and is then isolated from the heap.
			- Heapify is then applied to the remaining elements, and this process continues until a sorted array is finally obtained. 
		*/
		heapify(vals,i);
		swap(vals[0],vals[i-1]);
	}
}

int main(){
	vector<int> vals{3,6,7,4,2,5,1};
	heap_sort(vals);

	// Prints a sorted representation of the vector 'vals'
	for(int i=0;i<(int)vals.size();++i) cout<<vals[i]<<" ";
	cout<<endl;
	return 0;
}