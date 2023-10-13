import java.util.Scanner;

public class Main {
    public static long fibo(long n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fibo(n - 1) + fibo(n - 2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n, total;
        n = scanner.nextLong();
        total = fibo(n);
        System.out.println(total);
    }
}
