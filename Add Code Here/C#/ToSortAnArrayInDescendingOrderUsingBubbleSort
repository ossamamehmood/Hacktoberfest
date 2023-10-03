//C# program to implement bubble to sort an array 
//in descending order.

using System;

class Sort
{
    static void BubbleSort(ref int []intArr)
    {
        int temp=0;
        
        int pass = 0;
        int loop = 0;

        for ( pass= 0; pass <= intArr.Length - 2; pass++)
        {
            for ( loop = 0; loop <= intArr.Length - 2; loop++)
            {
                if (intArr[loop] < intArr[loop + 1])
                {
                    temp = intArr[loop + 1];
                    intArr[loop + 1] = intArr[loop];
                    intArr[loop] = temp;
                }
            }
        }
    }
    static void Main(string[] args)
    {
        int[] intArry = new int[5] { 65,34,23,76,21 };

        Console.WriteLine("Array before sorting: ");
        for (int i = 0; i < intArry.Length; i++)
        {
            Console.Write(intArry[i]+" ");
        }
        Console.WriteLine();

        BubbleSort(ref intArry);
        
        Console.WriteLine("Array before sorting: ");
        for (int i = 0; i < intArry.Length; i++)
        {
            Console.Write(intArry[i] + " ");
        }
        Console.WriteLine();
    }
}
