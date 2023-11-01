import java.util.*;

public class Calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean continueCalculating = true;

        while (continueCalculating) {
            System.out.println("Enter a: ");
            int a = sc.nextInt();
            System.out.println("Enter b: ");
            int b = sc.nextInt();
            System.out.println("Enter operator: ");
            char operator = sc.next().charAt(0);

            int result = 0;
            switch (operator) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '/':
                    if (b != 0) {
                        result = a / b;
                    } else {
                        System.out.println("Division by zero is not allowed.");
                        continue;
                    }
                    break;
                case '*':
                    result = a * b;
                    break;
                case '%':
                    if (b != 0) {
                        result = a % b;
                    } else {
                        System.out.println("Modulo by zero is not allowed.");
                        continue;
                    }
                    break;
                default:
                    System.out.println("Wrong operator");
                    continue;
            }

            System.out.println("Result: " + result);

            // Ask if the user wants to continue
            System.out.println("Do you want to perform another calculation? (Y/N)");
            char choice = sc.next().charAt(0);
            if (choice != 'Y' && choice != 'y') {
                continueCalculating = false;
            }
        }

        sc.close();
    }
}
