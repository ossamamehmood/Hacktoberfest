import java.util.Scanner;

public class EvenOdd_UsingBitwise {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();

        String result = ((num & 1) == 1) ? "Number is odd" : "Number is even";
        System.out.println(result);
    }
}
