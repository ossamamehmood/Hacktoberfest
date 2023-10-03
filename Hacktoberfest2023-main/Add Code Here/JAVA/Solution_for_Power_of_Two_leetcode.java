import java.util.Scanner;

public class SolutionByHarshPandey {
    public static boolean isPowerOfTwo(int n) {
        return (n&(n-1))==0&&n>0;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n=sc.nextInt();
        boolean binary = SolutionByHarshPandey.isPowerOfTwo(n);
        if (binary==true)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}