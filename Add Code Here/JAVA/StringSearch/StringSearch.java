

import java.io.*;

class StringSearch {
	public static void main(String[] args)
	{

		String text = "jutika is a coder";
		String pattern = "jutika";

		stringMatch(text, pattern);
	}
	public static void stringMatch(String text, String pattern)
	{

		int len_t = text.length();
		int len_p = pattern.length();

		int k = 0, i = 0, j = 0;
		for (i = 0; i <= (len_t - len_p); i++) {

			for (j = 0; j < len_p; j++)
			{
				if (text.charAt(i + j) != pattern.charAt(j))
					break;
			}
			
			if (j == len_p)
			{
				k++;
				System.out.println("Pattern Found at Position: " + i);
			}
		}
		
		if (k == 0)
			System.out.println("No Match Found!");
		else
			System.out.println("Total Instances Found = " + k);
	}
}
