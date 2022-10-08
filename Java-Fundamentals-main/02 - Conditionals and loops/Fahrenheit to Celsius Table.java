import java.util.Scanner;

public class Solution {


	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
		
        Scanner scn = new Scanner(System.in);
        int s,e,w;
        
        s = scn.nextInt();
        e = scn.nextInt();
        w = scn.nextInt();
        
        while(s <= e)
        {
            int ans = ((s-32)*5/9);
            System.out.println(s+" "+ans);
            s += w;
        }
        
		
	}

}
