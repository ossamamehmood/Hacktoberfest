import java.util.Scanner;

public class DecimalToBinary {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a decimal number: ");
        int decimal = scanner.nextInt();
        
        String binary = convertToBinary(decimal);
        
        System.out.println("Binary equivalent: " + binary);
        
        scanner.close();
    }
    
    public static String convertToBinary(int decimal) {
        if (decimal == 0) {
            return "0";
        }
        
        StringBuilder binary = new StringBuilder();
        
        while (decimal > 0) {
            int remainder = decimal % 2;
            binary.insert(0, remainder); // Prepend the remainder to the binary string
            decimal /= 2; // Divide the decimal number by 2
        }
        
        return binary.toString();
    }
}
