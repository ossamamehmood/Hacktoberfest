import java.util.Scanner;

public class NumberFinder
{
  public static void main(String args[])
  {

    Scanner input = new Scanner(System.in);
    int num;  
    System.out.println("Enter your number:");
    num = input.nextInt();

     
    if ( num % 2 == 0 )
        System.out.println("Hi you entered number is even");
     else
        System.out.println("Hi, you entered number is odd");
  }
}
