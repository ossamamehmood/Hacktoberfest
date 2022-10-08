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
            for(int j=1;j<=n-i;j++)
                System.out.print(" ");
            int k = i;
            for(int j=1;j<=i;j++)
            {
                System.out.print(k++);
            }
            --k;
            for(int j=1;j<=i-1;j++)
                System.out.print(--k);
            System.out.println();
        }
        
        
        
	}
}
