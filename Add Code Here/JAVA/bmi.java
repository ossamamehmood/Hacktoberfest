import java.util.Scanner;
public class bmi{
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Pounds: ");
        double pounds = scan.nextDouble();
        System.out.print("\nInches: ");
        double height = scan.nextDouble();
        double bmi = pounds/height/height*703;
        String round = String.format("%.2f", bmi);
        System.out.print("\nBMI: "+round+" kg/m2");
    }
}