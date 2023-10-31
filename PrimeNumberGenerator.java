import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PrimeNumberGenerator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the start of the range: ");
        int startRange = sc.nextInt();

        System.out.print("Enter the end of the range: ");
        int endRange = sc.nextInt();

        if (startRange > endRange) {
            System.out.println("Invalid range. The start of the range should be less than or equal to the end.");
        } else {
            List<Integer> primeNumbers = generatePrimesInRange(startRange, endRange);

            System.out.println("Prime numbers between " + startRange + " and " + endRange + ":");
            for (int prime : primeNumbers) {
                System.out.print(prime + " ");
            }
        }

        sc.close();
    }

    // Function to generate prime numbers within a specified range
    public static List<Integer> generatePrimesInRange(int start, int end) {
        List<Integer> primeNumbers = new ArrayList<>();

        for (int num = start; num <= end; num++) {
            if (isPrime(num)) {
                primeNumbers.add(num);
            }
        }

        return primeNumbers;
    }

    // Function to check if a number is prime
    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num <= 3) {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0) {
            return false;
        }

        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
}
