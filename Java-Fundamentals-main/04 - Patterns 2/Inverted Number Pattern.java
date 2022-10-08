import java.util.Scanner;


public class Solution {


	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
		
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        int k = n;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            	System.out.print(k);
            k--;
            System.out.println();
        }
		
	}

}
