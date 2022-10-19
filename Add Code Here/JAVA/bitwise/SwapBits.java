package com.topics.mathsForDSA.bitwiseOperators;

public class SwapBits {
    public static void main(String[] args) {
        long n = 0b10010010 ;
        swap(n,1,6);


    }

    static void swap (long n,int i,int j){
        if (((n >> i) & 1) != ((n >> j) & 1)){
            long mask = (1l<<i) | (1l<<j);
            n = n ^ mask;
            System.out.println(Long.toBinaryString(n));
        }
    }
}
