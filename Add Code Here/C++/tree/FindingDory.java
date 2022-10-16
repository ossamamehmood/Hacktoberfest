package loops;

import java.util.Scanner;

public class FindingDory {

	public static void main(String[] args) {
		
		Scanner sc= new Scanner(System.in);
		  
/*My friend generated a series 1 4 8 9 12 17 25 28 .... . Each element of this series is known as "Dory". Your task is to find out whether a number n is Dory or not.
NOTE: If n is "Dory", then return 1 else return 0.*/
	         
	  
		{
	            int n = sc.nextInt();

	            double sum1 = (5*n + 4);
	            double k1 = Math.sqrt(sum1);
	            double sum2 = (5*n - 4);
	            double k2 = Math.sqrt(sum2);

	            if(((int)(sum1/k1) == k1 )||((int)(sum2/k2) == k2 ) )
	            {
	                System.out.println("The number is Dory 1" );
	            }
	            else
	            {
	                System.out.println("The number is not Dory 0" );
	            }

	}

	}
}
