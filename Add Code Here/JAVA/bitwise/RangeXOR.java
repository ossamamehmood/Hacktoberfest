package com.topics.mathsForDSA.bitwiseOperators;

public class RangeXOR {
    public static void main(String[] args) {
        System.out.println(xor(9));
        System.out.println(xorab(3,9));

    }
    //this gives xor a,b
    static int xorab(int a,int b){
        int ans = xor(b) ^ xor(a-1);
        return ans;
    }

    //this gives xor from 0 to a
    static int xor(int a){
        if (a%4 == 0){
            return a;
        }
        if (a%4 == 1){
            return 1;
        }
        if (a%4 == 2){
            return a+1;
        }
        return 0;

    }
}

