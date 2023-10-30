//Buterfly Pattern using Java Nested Loop:)
import java.util.*;
public class Butterfly{
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter Num Of Lines : ");
        int num = scn.nextInt();
        butterfly(num);
        butterflyA(num);
    }

    public static void butterflyA(int a){
        //Outer Loop 
        for(int i =1; i<=a; i++){
            //Inner Loop 
            //First value 
            for(int j=1; j<=i; j++){
                System.out.print("@");
            }
            //for Space
            for (int j = 1; j<=2*(a-i);j++){
                System.out.print(" ");
            }
            //First value
            for(int j=1; j<=i; j++){
                System.out.print("@");
            }
            System.out.println();
        }
        for(int i = a; i>=1; i--){
                        //Inner Loop 
            //First value 
            for(int j=1; j<=i; j++){
                System.out.print("@");
            }
            //for Space
            for (int j = 1; j<=2*(a-i);j++){
                System.out.print(" ");
            }
            //First value
            for(int j=1; j<=i; j++){
                System.out.print("@");
            }
            System.out.println();
        }

    }

    public static void butterfly(int a){
        //Outer Loop
        for(int i=1; i<=a; i++){
            //inner loop 
            //for Star
            for (int j=1; j<=i; j++){
                System.out.print("*");

            }
            //for space
            for (int j=1; j<=2*(a-i);j++){
                System.out.print(" ");
            }
            //for Star
            for (int j=1; j<=i; j++){
                System.out.print("*");

            }
            System.out.println();
            
        }
        for(int i=a; i>=1; i--){
            //inner loop 
            //for Star
            for (int j=1; j<=i; j++){
                System.out.print("*");

            }
            //for space
            for (int j=1; j<=2*(a-i);j++){
                System.out.print(" ");
            }
            //for Star
            for (int j=1; j<=i; j++){
                System.out.print("*");

            }
            System.out.println();
            
        }
    }
}