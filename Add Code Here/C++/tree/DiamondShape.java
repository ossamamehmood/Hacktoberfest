import java.util.Scanner;
public class DiamondShape {

   public static void main(String[] args) {
       int i, j, k, temp = 1;
       for (i = 0; i < 5; i++) {
           for (k = i; k < 4; k++)
               System.out.print(" ");
           System.out.print("*");
           if (i != 0) {
               for (j = 1; j <= temp; j++)
                   System.out.print(" ");
               System.out.print("*");
               temp += 2;
           }
           System.out.println();
       }
       temp-=4;
       for(i=0;i<4;i++){
           for(k=0;k<=i;k++)
               System.out.print(" ");
           System.out.print("*");
           if(i!=3){
               for(j=1;j<=temp;j++)
                   System.out.print(" ");
               System.out.print("*");
               temp-=2;
           }
           System.out.println();
       }
   }
}
