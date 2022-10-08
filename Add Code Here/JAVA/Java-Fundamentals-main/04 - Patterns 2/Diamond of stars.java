import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        for(int i=1;i<=n;i++)
        {
            int k = (n+1)/2;
           	if(i<=(n+1)/2)
            { 
         		for(int j=1;j<=k-i;j++)
                    System.out.print(" ");
                for(int j=1;j<=2*i-1;j++)
                    System.out.print("*");
            }
            else
            {
                for(int j=1;j<=i-k;j++)
                    System.out.print(" ");
                for(int j=1;j<=2*(n-i)+1;j++)
                    System.out.print("*");
            }
            System.out.println();
        }
        
        
        
	}
}
