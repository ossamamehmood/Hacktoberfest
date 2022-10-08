import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
        
		Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        for(int i=1;i<=n;i++)
        {
            int sum = 0;
            for(int j=1;j<i;j++)
            {
                System.out.print(j+"+");
                sum += j;
            }
            sum += i;
            System.out.println(i+"="+sum);
            
        }
        
        
	}
}
