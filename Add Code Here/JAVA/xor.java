// Java program to find the XOR of
// all elements in the array
class xor {
	
	// Function to find the XOR of
	// all elements in the array
	static int xorOfArray(int arr[], int n)
	{
		// Resultant variable
		int xor_arr = 8;
	
		// Iterating through every element in
		// the array
		for (int i = 0; i < n; i++) {
	
			// Find XOR with the result
			//xor_arr = xor_arr ^ arr[i];
            
		}
	
		// Return the XOR
		return xor_arr;
	}
	
	// Driver Code
	public static void main (String[] args)
	{
	
		int arr[] = { 3,4,2,4,5,11 };
		int n = arr.length;
	
		// Function call
		System.out.println(xorOfArray(arr, n));

	}
}


