// Take 2 numbers as inputs and find their HCF and LCM.

import java.util.Scanner;
public class lcm {
    public static void main(String[] args) {
        Scanner no = new Scanner(System.in);
        System.out.print("Enter the first no.: ");
        int x = no.nextInt();
        System.out.print("Enter the Second no.: ");
        int y = no.nextInt();
        int i;
        int a = (x>y)? x : y;
        for (i = a; i <= x * y; i = i + a)
        {
            if(i % x == 0 && i % y == 0)
            break;
        }
        System.out.println("The LCM of " + x + " and " + y + " is " + i);
    }    
}
