import java.util.Scanner;


public class Solution {


	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
		
		Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        int f = 1;
        int s = 1;
        
        if(n<=2)
			System.out.println(1);
        else
        {
            int res = 0;
            for(int i=3;i<=n;i++)
            {
                res = f+s;
                f = s;
                s = res;
            }
            System.out.println(res);
        }
        
	}

}
