//Let's Create a Palindromic Pattern with Numbers using java:)
import java.util.*;
public class Palindromic{
    public static  void main(String args[]){
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter the num of Lines : ");
        int num = scn.nextInt();
        palindromic(num);
    }

    public static void palindromic(int n){
        //Outer Loop
        for(int i=1; i<=n; i++){
            //Space
            for (int s=1; s<=n-i; s++){
                System.out.print(" ");
            }
                for(int des=i; des>=1; des--){
                    System.out.print(des);
                }
                for(int asn=2; asn<=i; asn++){
                    System.out.print(asn);
                }
            
            System.out.println();
        }
    }

}