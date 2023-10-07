import java.util.*;  
import java.lang.Math;  
public class Main
{  
    static boolean isArmstrong(int n)   
    {   
        int t1, dig=0, l1=0, sum=0;   
        t1=n;   

        while(t1>0)    
        {   
            t1 = t1/10;   
            dig++;   
        }   
        t1 = n;   
        while(t1>0)   
        {   
            l1 = t1 % 10;   
            sum += (Math.pow(l1, dig));   
            t1 = t1/10;   
        }  
        if(n==sum)   
            return true;      
        else 
            return false;   
    }   
    //driver code  
    public static void  main(String args[])     
    {     
        int numb;   
        Scanner sc= new Scanner(System.in);  
        System.out.print("Enter the numbber: ");  
        numb=sc.nextInt();  
        if(isArmstrong(numb))  
        {  
            System.out.print("Armstrong ");  
        }  
        else   
        {  
            System.out.print("Not Armstrong ");  
        }  
    }   
}  
