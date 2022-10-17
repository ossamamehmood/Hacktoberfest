package com.topics.mathsForDSA.bitwiseOperators;

public class SetBits {
    public static void main(String[] args) {
        int n = 111;
        System.out.println(Integer.toBinaryString(n));
        System.out.println(setBits(n));

    }
    static int setBits(int n){
        int count = 0;
        while (n>0){
            count++;
            n -= (n & -n);
        }
        return count;
    }

    //ALITER
//    static int setBits(int n){
//        int count = 0;
//        while (n>0){
//            count++;
//            n = n& (n-1);
//        }
//        return count;
//    }
}
