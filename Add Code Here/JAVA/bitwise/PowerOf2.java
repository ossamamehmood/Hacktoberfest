package com.topics.mathsForDSA.bitwiseOperators;

public class PowerOf2 {
    public static void main(String[] args) {
        int n = 32;
        boolean ans;
        if (n == 0)
            ans = false;
        else ans = (n & (n-1)) ==0 ;
        System.out.println(ans);

    }
}
