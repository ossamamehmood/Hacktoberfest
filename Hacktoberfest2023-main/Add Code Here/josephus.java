
package com.mycompany.dsa;


public class josephus {
    
    public static int jos(int n,int k)
    {
        if(n==1)
        {
            return 0;
        }
        return ((jos(n-1,k)+k)%n);
    }
    
    public static void main(String[] args)
    {
        int a=jos(5,3);
        System.out.println("Person no. "+a+" will be alive");
    }
}
