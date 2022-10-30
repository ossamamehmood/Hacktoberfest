#Find the element that appears once in an array where every other element appears twice

import java.io.*;
class Solution {

// Function to find the
static int findSingle(int A[], int ar_size)
{

	// Iterate over every element
	for (int i = 0; i < ar_size; i++) {

	// Initialize count to 0
	int count = 0;

	for (int j = 0; j < ar_size; j++) {

		// Count the frequency
		// of the element
		if (A[i] == A[j]) {
		count++;
		}
	}

	// if the frequency of the
	// element is one
	if (count == 1) {
		return A[i];
	}
	}

	// if no element exist at most once
	return -1;
}

public static void main (String[] args) {
	int ar[] = { 2, 3, 5, 4, 5, 3, 4 };
	int n = ar.length;

	// Function call
	System.out.println("Element occurring once is " + findSingle(ar, n));
}
}
