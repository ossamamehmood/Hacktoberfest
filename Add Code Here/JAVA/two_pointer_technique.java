// Java Program Illustrating Naive Approach to
// Find if There is a Pair in A[0..N-1] with Given Sum

// Importing all input output classes
import java.io.*;

// Main class
class GFG {

	// Method 1
	// Main driver method
	public static void main(String[] args)
	{
		// Declaring and initializing array
		int arr[] = { 2, 3, 5, 8, 9, 10, 11 };

		int val = 17;

		System.out.println(isPairSum(arr, arr.length, val));
	}

	// Method 2
	// To find Pairs in A[0..N-1] with given sum
	private static int isPairSum(int A[], int N, int X)
	{
		// Nested for loops for iterations
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				// As equal i and j means same element
				if (i == j)

					// continue keyword skips the execution
					// for following condition
					continue;

				// Condition check if pair exists
				if (A[i] + A[j] == X)
					return 1;

				// By now the array is sorted
				if (A[i] + A[j] > X)

					// Break keyword to hault the execution
					break;
			}
		}

		// No pair found with given sum.
		return 0;
	}
}
