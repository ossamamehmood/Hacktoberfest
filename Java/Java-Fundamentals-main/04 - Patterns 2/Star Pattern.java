import java.util.Scanner;

public class Solution {


	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
        
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        int cnt = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
                System.out.print(" ");
            for(int j=1;j<=cnt;j++)
                System.out.print("*");
            cnt += 2;
            System.out.println();
        }

		
	}

}
