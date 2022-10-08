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
            char ch = (char)(65+i-1);
            for(int j=1;j<=i;j++)
            {
                System.out.print(ch);
            }
            System.out.println();
        }
		
	}

}