
import java.util.Scanner;

public class Solution {


	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/
	
        Scanner scn = new Scanner(System.in);
        
        char ch = scn.next().charAt(0);
        int a = scn.nextInt();
		int b = scn.nextInt();
        int c = scn.nextInt();
        
        System.out.println(ch);
        System.out.println((a+b+c)/3);
	}

}
