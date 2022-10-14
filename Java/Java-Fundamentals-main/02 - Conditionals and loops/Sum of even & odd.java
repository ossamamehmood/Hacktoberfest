import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		// Write your code here
		Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        int es = 0;
        int os = 0;
        
        while(n>0)
        {
            int d = n%10;
            if(d%2 == 0)
                es += d;
            else
                os += d;
            n /= 10;
        }
        
        System.out.println(es+" "+os);
	}
}
