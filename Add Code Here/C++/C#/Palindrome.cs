using System;
					
public class Program
{
	public static void Main()
	{
		    string initial = "";
		    
		    Console.WriteLine("Enter a String to check for Palindrome");
 
            string input = Console.ReadLine();
 
            int iLength = input.Length;
 
		    //check if string length is not 0, basically if it is not empty
            if (iLength == 0)
            {
                Console.WriteLine("You did not enter the string");
 
            }
            else
            { 
                for (int j = iLength - 1; j >= 0; j--)
                {
                    initial = initial + input[j];
                }				
 				//if initial string is same as input
                if (initial == input)
                {
                    Console.WriteLine(input + " is palindrome");
                }
                else
                {
                    Console.WriteLine(input + " is not a palindrome");
                }
             
            }
	}
}
