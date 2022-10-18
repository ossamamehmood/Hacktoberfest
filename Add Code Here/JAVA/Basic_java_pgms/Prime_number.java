import java.util.Scanner;

public class Prime_number {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println(prime_no(num));
    }

    private static String prime_no(int num) {
        int n = 2 ;
        while(n * n <=num){
            if (num % n == 0){
                return "Not prime";
            } else {
                n = n + 1;
            }
        }
        return "Prime";
    }
}


