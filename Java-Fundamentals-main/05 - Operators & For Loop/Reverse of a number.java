import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		// Write your code here
		
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        int rev = 0;
        
        while(n != 0)
        {
            int dig = n%10;
            rev *= 10;
            rev += dig;
            
            n /= 10;
        }
        
        System.out.println(rev);
        
	}
}
