import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        int j = 0;
        
        for(int i=0;i*i<=n;i++)
        {
            if(i*i == n)
            {
                System.out.println(i);
                return;
            }
            j = i;
        }
        
        System.out.println(j);

	}
}
