import java.util.Arrays;

public class LongestCommonSubsequence_BruteForce {
    static int lcsUtil(int m,int n,String a, String b)
    {
        if(m==0 || n==0)
        return 0;

        if(a.charAt(m-1)==b.charAt(n-1))
            return 1+lcsUtil(m-1, n-1, a, b);
        else
        {
            return Math.max(lcsUtil(m-1, n, a, b), lcsUtil(m, n-1, a, b));
        }
    }
    public static void main(String[] args) {
        System.out.println(lcsUtil(4, 5, "abcd", "bcedf"));
    }
}
