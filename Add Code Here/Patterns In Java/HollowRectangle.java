import java.util.*;

public class HollowRectangle{
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter the Num of Rows : ");
        int row = scn.nextInt();
        System.out.print("Enter the Num of Collumn : ");
        int col = scn.nextInt();
        pr_rec(row, col);
    }

    public static void pr_rec(int a , int b){
        //Outer Loop
        for(int i = 1; i <= a; i++ ){
            //Iner Loop mean collum
            for(int j = 1; j <= b; j++){
                //check boundary of cell
                if (j == 1 || i == 1 || i == a || j == b ){
                    System.out.print("*");

                } else{
                   System.out.print(" ");
                }
                
               

            }
            System.out.println();
        }
    }
}