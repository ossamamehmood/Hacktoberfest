import java.util.*;
public class RtdHalfPyramid{
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter the Num of Rows : ");
        int num_rows = scn.nextInt();
        halfPyramid(num_rows);

    }

    public static void halfPyramid(int a){
        //outer loop 
        for(int i = 1 ; i <= a; i++){
            //inner loop for space
            for (int j = 1; j <= a - i; j++){
                System.out.print(" ");  
            }
            //inner loop for stars
            for(int j=1; j <= i; j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}