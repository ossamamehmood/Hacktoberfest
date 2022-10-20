import java.util.Scanner;

public class FizzBuzz {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um valor inteiro: ");

        Integer entradaNumero = scanner.nextInt();
        scanner.close();

        for (int i = 1; i <= entradaNumero; i++) {

            if (i % 3 == 0 && i % 5 != 0) {
                System.out.println("Fizz");
            }
            else if (i % 5 == 0 && i % 3 != 0) {
                System.out.println("Buzz");
            }
            else if (i % 3 == 0 && i % 5 == 0) {
                System.out.println("FizzBuzz");
            } else {
                System.out.println(i);
            }

        }
    }


}