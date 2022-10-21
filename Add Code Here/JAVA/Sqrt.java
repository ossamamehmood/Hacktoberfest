import java.util.Scanner;

public class sqrt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number ");
        double x = sc.nextDouble();
        if (x == 0) {
            System.out.println("The square root of " + x + " is " + x);
        }
        if (x == 1) {
            System.out.println("The square root of " + x + " is " + x);
        }
        double start = 0;
        double end = x;
        double res = 0;
        while (start <= end) {
            double mid = start + (end - start) / 2;
            if (mid <= x / mid) {
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        System.out.println("The square root of " + x + " is " + res);
    }
}
