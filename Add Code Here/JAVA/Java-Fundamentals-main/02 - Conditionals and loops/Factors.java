import java.util.Scanner;

public class Solution {
    
    public static void main(String[] args) {
        // Write your code here
        Scanner scn = new Scanner(System.in);
        
        int n = scn.nextInt();
        
        for(int i=2;i<n;i++)
        {
            if(n%i == 0)
                System.out.print(i+" ");

        }
        
    }
}