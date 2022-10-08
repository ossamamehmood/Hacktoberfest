import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
		
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        int c = scn.nextInt();
        
        if(c == 1)
        {
            System.out.print((n*(n+1))/2);
        }
        else if(c == 2)
        {
            int res = 1;
            for(int i=1;i<=n;i++)
                res *= i;
            System.out.print(res);
        }
        else
        {
            System.out.print(-1);
        }
        
	}
}
