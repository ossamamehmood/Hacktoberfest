// Github username: ManishGhimire127
// Aim: Create any Right Triangle Star Pattern
// Date: 21 Oct, 2022

// Task: Create any pattern
// Right Triangle Star Pattern

import java.util.Scanner;
public class RightTrianglePattern   
{   
public static void main(String args[])   
{
    System.out.print("Enter number of rows: ");
    Scanner sc = new Scanner(System.in);
    int row = sc.nextInt();
    int i, j;   
    for(i=0; i<row; i++)   
{   
    for(j=0; j<=i; j++)   
{   
    System.out.print("* ");   
}   
System.out.println();   
}   
}   
}  