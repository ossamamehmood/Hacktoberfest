import java.util.Scanner;

public class FibonacciGenerator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of terms in the Fibonacci sequence: ");
        int numTerms = sc.nextInt();

        generateFibonacci(numTerms);

        sc.close();
    }

    public static void generateFibonacci(int numTerms) {
        int a = 0, b = 1;
        System.out.println("Fibonacci sequence up to " + numTerms + " terms:");
        System.out.print(a + " "); // Print the first term

        if (numTerms > 1) {
            System.out.print(b + " "); // Print the second term
        }

        for (int i = 2; i < numTerms; i++) {
            int next = a + b;
            System.out.print(next + " "); // Print the next term
            a = b;
            b = next;
        }

        System.out.println(); // Print a newline at the end
    }
}
