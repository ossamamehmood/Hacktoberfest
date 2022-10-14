import java.util.*;  
import java.lang.Math;  
public class Main
{  
    static int sum(int n1,int n2)   
    {   
        return n1+n2;
    }   

    static int prod(int n1,int n2)   
    {   
        return n1*n2;
    }


    public static void  main(String args[])     
    {     
        int numb1,numb2;   
        Scanner sc= new Scanner(System.in);  
        System.out.print("Enter the First numbber: ");  
        numb1=sc.nextInt();
        System.out.print("Enter the Second numbber: ");  
        numb2=sc.nextInt();

        System.out.println("Difference between sum and product (sum - product) : " + (sum(numb1,numb2) - prod(numb1,numb2))); 
        System.out.println("Difference between sum and product (Product - Sum) : " + (prod(numb1,numb2) - sum(numb1,numb2))); 
    }   
}  
