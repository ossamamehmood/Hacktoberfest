package com.topics.mathsForDSA.bitwiseOperators;

import com.sun.security.jgss.GSSUtil;



public class IthBit {
    public static void main(String[] args) {
        int n = 18;
        int x = ~n + 1;
        System.out.println(x);
        boolean ans = ~(n-1) == ~n + 1;
        System.out.println(ans);

    }



}
