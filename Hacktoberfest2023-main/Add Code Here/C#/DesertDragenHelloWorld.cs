using System;

class Program
{
    static void Main()
    {
         // Print a greeting message
        Console.WriteLine("DesertDragen says: Hello, World!");

        // Prompt the user to enter some input
        Console.Write("Enter something: ");
        
        // Read the user's input
        string userInput = Console.ReadLine();
        
        // Print the input provided by the user
        Console.WriteLine("You entered: " + userInput);
    }
}
