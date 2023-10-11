package Java.Leetcode;


//      Q : 372. Super Pow

public class SuperPow {
    public int superPow(int a, int[] b) {
        int ref = 0;
        for (int i = 0; i < b.length; i++) {
            ref = ref * 10 + b[i];
        }
        return (int) Math.pow(a, ref);
    }
}
