 // Downward Triangle Star Pattern by Raj Kasaudhan
 // Date of code : 21 October, 20
 //github username: www.github.com/rajksd01
 // Aim: Create any pattern 
 // Task: Downward Triangle Star Pattern
 
 import java.util.Scanner;
 class trianglePattern {

    public static void main(String[] args) {
        System.out.println("Enter the number of rows");// User input for number of rows
        Scanner in = new Scanner(System.in);
        int rows = in.nextInt();

        for(int i = rows; i >= 1; --i) {  //For Loop for Row 

            for(int j = 1; j <= i; ++j) { //For Loop for Column

                System.out.print("* "); //Prints *

            }

            System.out.println(); //Moves to newline

        }
        in.close();

    }

}
