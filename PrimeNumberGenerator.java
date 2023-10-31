import java.util.Scanner;

public class PrimeNumberGenerator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the end of the range: ");
        int endRange = sc.nextInt();

        boolean[] isPrime = sieveOfEratosthenes(endRange);

        System.out.println("Prime numbers up to " + endRange + ":");
        for (int i = 2; i <= endRange; i++) {
            if (isPrime[i]) {
                System.out.print(i + " ");
            }
        }

        sc.close();
    }

    public static boolean[] sieveOfEratosthenes(int n) {
        boolean[] isPrime = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            isPrime[i] = true;
        }

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        return isPrime;
    }
}
