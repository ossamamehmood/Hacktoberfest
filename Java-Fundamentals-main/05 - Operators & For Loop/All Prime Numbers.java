import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
		
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        for(int i=2;i<=n;i++)
        {
            int flg  = 1;
            
            for(int j=2;j*j<=i;j++)
            {
                if(i%j == 0)
                {
                    flg = 0;
                    break;
                }
            }
            
            if(flg == 1)
            {
                System.out.println(i);
            }
        }
		
	}
}
