import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println(reverse(num));
    }

     public static int reverse(int number){
        int reverse = 0;
        while (number > 0){
            int rem = number % 10;
            number = number / 10;
            reverse =  (reverse * 10) + rem;
        }
         return reverse;
     }


}
