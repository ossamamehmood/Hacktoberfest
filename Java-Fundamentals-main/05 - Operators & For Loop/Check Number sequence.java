import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		// Write your code here
        
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt(),i,count=0;
        int n1 = scn.nextInt(),n2 = scn.nextInt(),n3;
        
        for(i=0;i<t-2;i++)
        {
          n3 = scn.nextInt();
            
        	if(n1 == n2 || n2 == n3)
                count++;
                
            
          if((n1>n2)&&(n2<n3))
            count++;
          else if((n1<n2)&&(n2>n3))
            count++;
            
          n1 = n2;
          n2 = n3;
          
        }
        
        if(count>1)
          System.out.print("false");
        else
          System.out.print("true");

	}
}