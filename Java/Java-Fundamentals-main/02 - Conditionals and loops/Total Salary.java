import java.util.Scanner;
import java.lang.Math;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
		Scanner scn = new Scanner(System.in);
        int b = scn.nextInt();
        char ch = scn.next().charAt(0);
        
        float hra = (float)b*0.2f;
        float da = (float)b*0.5f;
        float pf = (float)b*0.11f;
        int allow;
        float total;
        
        if(ch == 'A')
            allow = 1700;
        else if(ch == 'B')
            allow = 1500;
        else
            allow = 1300;
           
    	total = (float)b+hra+da+(float)allow-pf;
        
        double res = Math.round(total);
    
        System.out.println((int)res);

        
	}
}
