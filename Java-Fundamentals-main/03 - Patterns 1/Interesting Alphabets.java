import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		//Your code goes here
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        for(int i=1;i<=n;i++)
        {
            char ch = (char)(65+(n-i));
            for(int j=1;j<=i;j++)
            {
                System.out.print(ch);
                ch += 1;
            }
            System.out.println();
        }
        
	}
}