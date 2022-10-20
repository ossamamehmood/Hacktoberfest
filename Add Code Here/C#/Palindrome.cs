using System;
					
public class Program
{
	public static void Main()
	{
		    string initial = "";
		    
		    Console.WriteLine("Enter a String to check for Palindrome");
 
            string input = Console.ReadLine();
 
            int Length = input.Length;
 
		    
            if (Length == 0)
            {
                Console.WriteLine("You did not enter the string");
 
            }
            else
            { 
                for (int j = Length - 1; j >= 0; j--)
                {
                    initial = initial + input[j];
                }				
 				
                if (initial == input)
                {
                    Console.WriteLine(input + " is palindrome Number");
                }
                else
                {
                    Console.WriteLine(input + " is not a palindrome Number");
                }
             
            }
	}
}
