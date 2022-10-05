public class ScientificCalculator extends Calculator implements IntfS, IntfR {
    public double exp(double a, double b) {
        return Math.pow(a, b);
    }

    public double sqrt(double a) {
        return Math.sqrt(a);
    }

    public double log(double a) {
        return Math.log10(a);
    }
}
