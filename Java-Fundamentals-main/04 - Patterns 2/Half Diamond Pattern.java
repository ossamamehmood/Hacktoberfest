import java.util.Scanner;

public class Solution {
    
    public static void main(String[] args) {
        // Write your code here
        
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        System.out.println("*");
        
        for(int i=1;i<=n;i++)
        {
            System.out.print("*");
            
            for(int j=1;j<=i;j++)
                System.out.print(j);
            
            for(int j=i-1;j>=1;j--)
                System.out.print(j);
            
            
            System.out.println("*");
        }
        
        for(int i=n-1;i>=1;i--)
        {
            System.out.print("*");
            
            for(int j=1;j<=i;j++)
                System.out.print(j);
            
            for(int j=i-1;j>=1;j--)
                System.out.print(j);
            
            
            System.out.println("*");
        }
        
        
        System.out.println("*");
        
    }
}