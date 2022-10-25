import java.util.*;

public class Fibonacci 
{
    public static void Fib(int n) 
    {
        int a = 0, b = 1, c;

        if (n == 1)
            System.out.println(a);
        else if (n == 2)
            System.out.println(a + " " + b);
        else
        {
            System.out.print(a + " " + b + " ");
            for(int i = 2; i < n; i++)
            {
                c = a + b;
                System.out.print(c + " ");
                a = b;
                b = c;
            }
        }    
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n;
        
        while(true)
        {
            System.out.print("Enter a number: ");
            n = sc.nextInt();
            
            if (n <= 0)
                System.out.println("Invalid input!!");
            else
                break;
        }
        
        System.out.println("Fibonacci Series Upto " + n + " terms: ");

        Fib(n);
        sc.close();
    }
}
