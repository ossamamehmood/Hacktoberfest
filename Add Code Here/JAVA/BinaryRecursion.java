public class BinarryRecursion {
    public static void main(String[] args) {
        int i = fibonacci(4);
        System.out.println(i);
    }
    
    public static int fibonacci(int i) {
        if (i == 1 || i == 2) {
            return 1;
        }
     
        return fibonacci(i-1) + fibonacci(i-2);
    }
    
}
