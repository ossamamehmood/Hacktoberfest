import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        int cnt = 0;
        int p = 1;
        
        while(cnt < n)
        {
            int term = 3*p+2;
            if(term % 4 == 0)
            {
                p++;
                continue;
            }
            else
            {
                System.out.print(term+" ");
                p++;
                cnt++;
            }
        }

	}
}
