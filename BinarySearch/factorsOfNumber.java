package com.BinarySearch;

public class factorsOfNumber {
    public static void main(String[] args) {
        System.out.println("Ganpati Bappa Morya 💖!!");
        // positive number
        int number = 5;

        System.out.print("Factors of " + number + " are: ");

        // loop runs from 1 to 60
        for (int i = 1; i <= number; ++i) {

            // if number is divided by i
            // i is the factor
            if (number % i == 0) {
                System.out.print(i + " ");
            }
        }
    }
}
