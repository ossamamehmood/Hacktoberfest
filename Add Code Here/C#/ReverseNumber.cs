using System;

public class ReverseNumber
{
    public static void Main(string[] args)
    {
        int number;
        int reverse=0;
        int rem;

        Console.Write("Enter a number: ");
        number= int.Parse(Console.ReadLine());
        
        while(number != 0)
        {
            rem = number % 10;
            reverse = reverse * 10 + rem;
            number /= 10;
        }

        Console.Write("Reversed Number: "+reverse);
    }
}