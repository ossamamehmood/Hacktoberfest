package LEasy;

public class MultipleRecursionCalls {
    public static void main(String[] args) {

        System.out.println(fib(10));

    }

    private static int fib(int n) {
        if(n<=1){
            return n;
        }

        return fib(n-1)+fib(n-2);
    }
}
