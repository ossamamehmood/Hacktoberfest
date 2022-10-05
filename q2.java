import java.util.Scanner;
public class q2 
{
    public static void main(String [] args)
    {
        Scanner obj= new Scanner(System.in);

        System.out.print("Enter any number: ");

        int number= obj.nextInt();

        obj.close();

        // if(number%2==0)
        // {
        //     System.out.print("Even Number");
        // }
        // else
        // {
        //     System.out.print("Odd Number");
        // }

        
        String result=(number%2==0) ? "Even" : "Odd";
        System.out.println(result);
    }
    
}