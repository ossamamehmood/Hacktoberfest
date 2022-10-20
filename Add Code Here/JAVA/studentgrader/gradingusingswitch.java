/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Hp
 */
import java.util.Scanner;
public class gradingusingswitch {
     public static void main(String[] args) {
        for(int i=0;i<=5;i++){
   
            System.out.println("Enter Student name followed by score: ");
            Scanner studentdata = new Scanner(System.in);

            String name = studentdata.nextLine();
            int score = studentdata.nextInt();


            System.out.println("Name: " + name + " Score: " + score );

            switch(score/ 10){
                    case 1:
                    case 5:
                       System.out.println("Grade: F");
                       break;
                    case 6:
                    case 10:
                        System.out.println("Grade: D");
                        break;
            }
        }
    }
    
}
