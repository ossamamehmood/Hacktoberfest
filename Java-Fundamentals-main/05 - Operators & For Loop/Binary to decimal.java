import java.util.Scanner;
import java.lang.Math;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        int res = 0;
        
        int power = 0;
        
        while(n != 0)
        {
            int dig = n %10;
            n /= 10;
            
            res += (dig*(Math.pow(2,power)));
            power++;
        }
        
        System.out.println(res);

	}
}