/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.howmanycharsinword;

/**
 *
 * @author Jude Darren Victoria
 */
import java.util.Scanner;
public class HowManyCharsinWord {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter a word");
        String word = sc.next(); 
        
        int count = word.length();

        System.out.println("The number of characters in the string is: " + count);
       
    }
}
