import java.util.Scanner;

public class Main {
    public static long factorial(long n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        else
            return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n, total;
        n = scanner.nextLong();
        total = factorial(n);
        System.out.println(total);
    }
}
