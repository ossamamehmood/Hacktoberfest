public class BhaskForm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double C = sc.nextDouble();
        double delta = Math.pow(B, 2) - (4 * (A * C));
        if (delta == 0 || delta < 0 || A == 0) {
            System.out.println("Impossivel calcular");
        } else {
            double x = -B + Math.sqrt(delta);
            double xlinha = x / (2 * A);
            double x2 = -B - Math.sqrt(delta);
            double xdualinha = x2 / (2 * A);
            System.out.printf("R1 = %.5f\n", xlinha);
            System.out.printf("R2 = %.5f\n", xdualinha);

        }
    }
    }
}
