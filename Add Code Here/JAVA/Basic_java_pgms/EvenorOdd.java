import java.util.Scanner;

public class EvenorOdd {
    public static void main(String[] args) {
        int number = 0;
        System.out.println(eve_odd(number));
    }

    private static String eve_odd(int number) {
        System.out.println("Enter the number :");
        Scanner sc = new Scanner(System.in);
        number = sc.nextInt();
        if (number % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }


}
