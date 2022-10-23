package com.topics.mathsForDSA.bitwiseOperators;

import java.util.Scanner;

public class NoOfDigitsInBaseB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int base = sc.nextInt();

        int ans = (int)(Math.log(n) / Math.log(base)) + 1 ;

        System.out.println(ans);


    }
}
