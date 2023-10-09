import java.util.Arrays;
import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the term up to which you want to find the Fibonacci series");
        int n = sc.nextInt();
        
        for (int i = 0; i < n; i++) {
            System.out.println(fib(i));
        }
    }

    static int fib(int n) {
        int[] arr = new int[n + 1]; 

        Arrays.fill(arr, -1);
        int res;
        if (arr[n] != -1) {
            return arr[n];
        }
        if (n == 0 || n == 1) {
            res = n;
        } else {
            res = fib(n - 1) + fib(n - 2);
        }
        arr[n] = res;
        return arr[n];
    }
}
