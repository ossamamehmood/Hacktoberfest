
import java.io.*;

class GFG {
	public static boolean isPalindrome(String str)
	{
		// Initializing an empty string to store the reverse
		// of the original str
		String rev = "";

		// Initializing a new boolean variable for the
		// answer
		boolean ans = false;

		for (int i = str.length() - 1; i >= 0; i--) {
			rev = rev + str.charAt(i);
		}

		// Checking if both the strings are equal
		if (str.equals(rev)) {
			ans = true;
		}
		return ans;
	}
	public static void main(String[] args)
	{
		// Input string
		String str = "geeks";

		// Convert the string to lowercase
		str = str.toLowerCase();
		boolean A = isPalindrome(str);
		System.out.println(A);
	}
}
