import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
import java.lang.Math;

public class TiposDeTriangulo {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Double[] ladosArray = new Double[3];

        System.out.print("Digite o tamanho de cada lado do triângulo: ");

        ladosArray[0] = scanner.nextDouble();
        ladosArray[1] = scanner.nextDouble();
        ladosArray[2] = scanner.nextDouble();

        scanner.close();

        Arrays.sort(ladosArray, Collections.reverseOrder());

        Double ladoA = ladosArray[0];
        Double ladoB = ladosArray[1];
        Double ladoC = ladosArray[2];

        if (ladoA >= ladoB + ladoC) {
            throw new RuntimeException("Não forma triângulo!");
        }

        if (((Double) Math.pow(ladoA, 2)).equals(Math.pow(Math.hypot(ladoB, ladoC), 2))) {
            System.out.println("Triâgulo Retângulo");
        } else if (Math.pow(ladoA, 2) > Math.pow(Math.hypot(ladoB, ladoC), 2)) {
            System.out.println("Triângulo Obtusângulo");
        } else {
            System.out.println("Triângulo Acutângulo");
        }

        if (ladoA.equals(ladoB) && ladoA.equals(ladoC)) {
            System.out.println("Triângulo Equilátero");
        } else if (ladoA.equals(ladoB) || ladoA.equals(ladoC) || ladoB.equals(ladoC)) {
            System.out.println("Triângulo Isósceles");
        }

    }

}