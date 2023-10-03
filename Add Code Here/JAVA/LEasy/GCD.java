import java.util.Scanner;

public class GCD {

    // Using the Euclidean algorithm to calculate GCD
    public static int euclideanGCD(int n1, int n2) {
        while (n2 != 0) {
            int temp = n1 % n2;
            n1 = n2;
            n2 = temp;
        }
        return n1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the first number: ");
        int n1 = scanner.nextInt();
        
        System.out.print("Enter the second number: ");
        int n2 = scanner.nextInt();

        int result = euclideanGCD(n1, n2);
        System.out.println("The GCD of " + n1 + " and " + n2 + " is: " + result);
    }
}
