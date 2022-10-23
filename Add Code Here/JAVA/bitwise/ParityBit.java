package com.topics.mathsForDSA.bitwiseOperators;

public class ParityBit {
    // Time complexity is O(n) , where n is the word size
    public static short parity(long x) {
        short result = 0;
        int count = 0;
        while (x != 0) {
            result ^= (x & 1);
            x >>= 1;
            count = count + 1;
        }
        System.out.println("Approach1:" + count);
        return result;
    }

    //O(k) k is no of set bits (1s)
    public static short parity1(long x) {
        short result = 0;
        int count = 0;
        while (x != 0) {
            result ^= 1;
            x = x & (x - 1); // Discards the lowest set bit
            count = count + 1;
        }
        System.out.println("Approach2:" + count);
        return result;
    }

    public static void main(String[] args) {
        short x = 0b1010; //10
        System.out.println(parity(x));
        System.out.println(parity1(x));
    }
}
