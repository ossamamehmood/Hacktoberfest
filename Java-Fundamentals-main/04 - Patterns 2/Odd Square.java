import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        for(int i=1;i<=n;i++)
        {
            for(int j=2*i-1;j<=n*2-1;j+=2)
                System.out.print(j);
            int k = 1;
            for(int j=1;j<=i-1;j++)
            {
                System.out.print(k);
                k += 2;
            }
            System.out.println();
        }
        
	}
}
