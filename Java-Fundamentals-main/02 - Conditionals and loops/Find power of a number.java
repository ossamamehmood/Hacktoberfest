import java.util.Scanner;



public class Solution {
    
    public static void main(String[] args) {
        // Write your code here
        Scanner scn = new Scanner(System.in);
        
        int n,a;
        n = scn.nextInt();
        a = scn.nextInt();
        
        int res = 1;
        int i = 0;
        
        while(i<a)
        {
            res = res*n;
            i++;
        }
        
        System.out.println(res);
        
    }
}