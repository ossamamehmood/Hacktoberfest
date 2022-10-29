import java.util.Scanner;

public class CodesCracker
{
   public static void main(String[] args)
   {
      int num, totalDigits;
      Scanner s = new Scanner(System.in);
      
      System.out.print("Enter a Number: ");
      num = s.nextInt();
      
      for(totalDigits=0; num!=0; num=num/10)
         totalDigits++;
      
      System.out.println("\nThe Total Number of Digits = " +totalDigits);
   }
}
