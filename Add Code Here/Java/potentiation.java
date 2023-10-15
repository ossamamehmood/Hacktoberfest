import java.util.Scanner;

public class Main {
    public static float pot(int a, int b) {
        if (b == 0 && a != 0)
            return 1;
        if (b >= 1)
            return a * pot(a, b - 1);
        if (b <= -1)
            return 1.0f / a * pot(a, b + 1);
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b;
        float total;
        a = scanner.nextInt();
        b = scanner.nextInt();

        if (a == 0 && b <= 0) {
            System.out.println("undefined");
        } else {
            total = pot(a, b);
            System.out.println(total);
        }
    }
}
