package com.topics.mathsForDSA.bitwiseOperators;

import java.util.Scanner;

public class OddEven {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(isOdd(n));
    }

    static boolean isOdd(int n){
        return (n & 1) == 1;

    }
}
