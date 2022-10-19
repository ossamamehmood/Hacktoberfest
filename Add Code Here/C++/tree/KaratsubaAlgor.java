/*
Karatsuba Algorithm for matrix multiplication.
*/

import java.util.*;


public class KaratsubaAlgo{



long karatsuba(long X, long Y){
        
        if(X<10 && Y<10){
	        return X*Y;
	    }
        
        
        int size = Math.max((Long.toString(X)).length(), (Long.toString(Y)).length());
        
        
        int n = (int)Math.ceil(size/2.0);
        long p = (long)Math.pow(10,n);
        long a = (long)Math.floor(X/(double)p);
        long b = X%p;
        long c = (long)Math.floor(Y/(double)p);
        long d = Y%p;
        
        
        long ac = karatsuba(a, c);
        long bd = karatsuba(b, d);
        long e = karatsuba(a+b, c+d) - ac - bd;
        
        
        return (long)(Math.pow(10*1L, 2*n)*ac + Math.pow(10*1L, n)*e + bd);
    }




public static void main (String[] args){

		Scanner input = new Scanner(System.in);
        
		System.out.println("Karatsuba  Algorithm\n");

		Main karatsubaMult = new Main();
 

		System.out.println("Enter two numbers: \n");
		long n1 = input.nextLong();
		long n2 = input.nextLong();

		long product = karatsubaMult.karatsuba(n1, n2);
		System.out.println("\nThe product is "+ product);
	}
}
