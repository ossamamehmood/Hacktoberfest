import java.util.Scanner;

public class feereport {
    private static final int NUM_STUDENTS = 5;
    private static final double TUITION_FEE = 1000.0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] names = new String[NUM_STUDENTS];
        double[] feesPaid = new double[NUM_STUDENTS];
        double[] feesDue = new double[NUM_STUDENTS];
        double totalFeesPaid = 0.0;
        double totalFeesDue = 0.0;

        // Input student data
        for (int i = 0; i < NUM_STUDENTS; i++) {
            System.out.print("Enter name of student " + (i + 1) + ": ");
            names[i] = scanner.nextLine();
            System.out.print("Enter fees paid by student " + (i + 1) + ": ");
            feesPaid[i] = scanner.nextDouble();
            scanner.nextLine(); // Consume newline character
            feesDue[i] = TUITION_FEE - feesPaid[i];
            totalFeesPaid += feesPaid[i];
            totalFeesDue += feesDue[i];
        }

        // Output fee report
        System.out.println("Fee Report");
        System.out.println("-----------");
        System.out.println("Name\t\tFees Paid\tFees Due");
        for (int i = 0; i < NUM_STUDENTS; i++) {
            System.out.printf("%-10s\t$%.2f\t\t$%.2f\n", names[i], feesPaid[i], feesDue[i]);
        }
        System.out.println("-----------");
        System.out.printf("Total\t\t$%.2f\t\t$%.2f\n", totalFeesPaid, totalFeesDue);
        scanner.close();
    }

}
